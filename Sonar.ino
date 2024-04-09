#include <Servo.h>

int servopin = 9;
int servopos;
int trigPin = 12;
int echoPin = 11;
int duration;
Servo myservo;
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  myservo.attach(9);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  

}

void loop() {
  
  for(int i = 0; i < 180; i++)
  {
    servopos = i;
    myservo.write(i);
    delay(10);
    
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(2);
    digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin,HIGH);
    distance = duration*0.034/2;
    
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");

    if(duration <= 1800)
    {
      digitalWrite(10,HIGH);
      delay(10);
      digitalWrite(10,LOW);
  
    }
  
  }
  for(int i = 180; i > 0;i--)
  {
    servopos = i;
    myservo.write(i);
    delay(10);

    digitalWrite(trigPin,LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin,HIGH);
    distance = duration*0.034/2;


    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    
    
    if(duration <= 1800)
    {
      digitalWrite(10,HIGH);
      delay(10);
      digitalWrite(10,LOW);

    }
 
    
  }
  
}
