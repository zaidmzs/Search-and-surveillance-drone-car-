
const int trigPin = 4;
const int echoPin = 5;
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  Serial.begin(9600);
  Serial.println("Start");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance < 60)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }
  else
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
  }

}
