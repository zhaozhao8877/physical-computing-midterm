#include "lib1.h"

int LEDPin = D7;
int PIRPPin = D2;
int PIRState = LOW;

int LEDPin2 = D4;

int var = 0;


void setup() {
  
  pinMode(PIRPPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  
  pinMode(LEDPin2,OUTPUT);
  digitalWrite(LEDPin2,LOW);
  
  Particle.subscribe("pika", lightup,"57003a001251353338363333");
  Particle.subscribe("pika2",lightdown,"57003a001251353338363333");
  
 
  Serial.begin(9600);

}

void loop() {

  var = digitalRead(PIRPPin);
 
   if(var == HIGH) {
    
    digitalWrite(LEDPin,HIGH);
    //Particle.publish("broken");
    delay(1);
    Particle.publish("pikafeed","57003a001251353338363333");
    }
  else {
    digitalWrite(LEDPin,LOW);
    }
}

void lightup(const char *event, const char *data) 

  {
    
    digitalWrite(LEDPin2, HIGH);
  }

void lightdown(const char *event, const char *data) 

  {
    
    digitalWrite(LEDPin2, LOW);
  }

