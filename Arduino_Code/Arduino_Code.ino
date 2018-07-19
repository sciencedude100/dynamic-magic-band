/* TODO List:
 * - add animations
 * - fix LED colors
 * - add serial control
 * - add bluetooth serial
*/
#include <Adafruit_NeoPixel.h>

int PIN = 4;
int NUM_LEDS = 7;
int BRIGHTNESS = 0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup(){
  strip.setBrightness(BRIGHTNESS);
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

uint16_t magic_kingdom[4][7] = {
  {strip.Color(60, 170, 250), strip.Color(250, 250, 250), strip.Color(60, 170, 250), strip.Color(250, 250, 250), strip.Color(60, 170, 250), strip.Color(250, 250, 250), strip.Color(60, 170, 250)},  // Main Magic Kingdom
  {strip.Color(20, 82, 20), strip.Color(20, 178, 20), strip.Color(120,60,20), strip.Color(20, 82, 20), strip.Color(20, 178, 20), strip.Color(120,60,20), strip.Color(20, 82, 20)},  // Adventureland
  {strip.Color(240, 220, 0), strip.Color(60, 170, 250), strip.Color(200,20,20), strip.Color(60, 170, 250), strip.Color(240, 220, 0), strip.Color(200,20,20), strip.Color(240, 220, 0)},  // Toontown
  {strip.Color(0, 10, 130), strip.Color(250, 250, 250), strip.Color(60, 170, 250), strip.Color(0, 10, 130), strip.Color(250, 250, 250), strip.Color(0, 10, 130), strip.Color(250, 250, 250)}   // Tomorrowland
};
uint16_t epcot_center[8][7] = {
  {strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250)},  // Main EPCOT Center
  {strip.Color(60, 170, 250), strip.Color(60, 170, 250), strip.Color(60, 170, 250), strip.Color(0, 10, 130), strip.Color(0, 10, 130), strip.Color(0, 10, 130), strip.Color(60, 170, 250)},  // The Seas
  {strip.Color(20, 82, 20), strip.Color(20, 178, 20), strip.Color(20, 178, 20), strip.Color(20, 178, 20), strip.Color(20, 178, 20), strip.Color(20, 178, 20), strip.Color(20, 178, 20)},  // The Land
  {strip.Color(200,20,20), strip.Color(250, 250, 250), strip.Color(140, 10, 200), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(140, 10, 200), strip.Color(250, 250, 250)},  // Imagination
  {strip.Color(250, 250, 250), strip.Color(9, 31, 87), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(9, 31, 87)},  // Horizons
  {strip.Color(0, 10, 130), strip.Color(120,60,20), strip.Color(120,60,20), strip.Color(120,60,20), strip.Color(200,20,20), strip.Color(120,60,20), strip.Color(120,60,20)},  // Abandoned Area (Ellen's Energy & Wonders of life)
  {strip.Color(240, 220, 0), strip.Color(250, 250, 250), strip.Color(240, 220, 0), strip.Color(250, 250, 250), strip.Color(240, 220, 0), strip.Color(250, 250, 250), strip.Color(240, 220, 0)},  // Test Track
  {strip.Color(200,20,20), strip.Color(250, 250, 250), strip.Color(200,20,20), strip.Color(250, 250, 250), strip.Color(0, 10, 130), strip.Color(0, 10, 130), strip.Color(250, 250, 250)}   // World Showcase
};
uint16_t hollywood_studios[4][7] = {
  {strip.Color(200,20,20), strip.Color(200,20,20), strip.Color(200,20,20), strip.Color(210, 120, 40), strip.Color(200,20,20), strip.Color(200,20,20), strip.Color(200,20,20)},  // Main Hollywood Studios
  {strip.Color(200,20,20), strip.Color(200,20,20), strip.Color(200,20,20), strip.Color(200,20,20), strip.Color(250, 250, 250), strip.Color(200,20,20), strip.Color(200,20,20)},  // Muppets this needs to alternate
  {strip.Color(200,20,20), strip.Color(200,20,20), strip.Color(250, 250, 250), strip.Color(200,20,20), strip.Color(200,20,20), strip.Color(200,20,20), strip.Color(200,20,20)},  // Main Street alternate Orange and Green
  {strip.Color(200,20,20), strip.Color(200,20,20), strip.Color(200,20,20), strip.Color(200,20,20), strip.Color(250, 250, 250), strip.Color(200,20,20), strip.Color(200,20,20)}   // Thrill random flashes of blue, yellow, and white
};
uint16_t hotel[6][7] = {
  {strip.Color(60, 170, 250), strip.Color(0, 10, 130), strip.Color(60, 170, 250), strip.Color(210, 120, 40), strip.Color(60, 170, 250), strip.Color(60, 170, 250), strip.Color(60, 170, 250)},  // Nemo (Use this for hotel building)
  {strip.Color(200,20,20), strip.Color(200,20,20), strip.Color(134, 3, 3), strip.Color(200,20,20), strip.Color(200,20,20), strip.Color(60, 170, 250), strip.Color(200,20,20)},  // Cars
  {strip.Color(250, 250, 250), strip.Color(200,20,20), strip.Color(180, 140, 10), strip.Color(120,60,20), strip.Color(250, 250, 250), strip.Color(20, 178, 20), strip.Color(250, 250, 250)},  // Toy Story
  {strip.Color(180, 140, 10), strip.Color(180, 140, 10), strip.Color(180, 140, 10), strip.Color(250, 250, 250), strip.Color(180, 140, 10), strip.Color(180, 140, 10), strip.Color(180, 140, 10)},  // Lion King breathing white here
  {strip.Color(20, 178, 20), strip.Color(20, 178, 20), strip.Color(20, 178, 20), strip.Color(140, 10, 200), strip.Color(200,20,20), strip.Color(0, 10, 130), strip.Color(0, 10, 130)}   // Little Mermaid
};
uint16_t animal_kingdom[5][7] = {
  {strip.Color(120,60,20), strip.Color(20, 82, 20), strip.Color(20, 82, 20), strip.Color(20, 82, 20), strip.Color(20, 82, 20), strip.Color(20, 82, 20), strip.Color(20, 82, 20)},  // Main Animal Kingdom
  {strip.Color(35, 83, 35), strip.Color(39, 71, 51), strip.Color(27, 76, 68), strip.Color(34, 73, 85), strip.Color(20, 70, 81), strip.Color(16, 67, 118), strip.Color(13, 64, 135)},  // Pandora
  {strip.Color(20, 82, 20), strip.Color(120,60,20), strip.Color(20, 82, 20), strip.Color(120,60,20), strip.Color(20, 82, 20), strip.Color(120,60,20), strip.Color(20, 82, 20)},  // Thrill
  {strip.Color(20, 82, 20), strip.Color(120,60,20), strip.Color(20, 82, 20), strip.Color(120,60,20), strip.Color(20, 82, 20), strip.Color(120,60,20), strip.Color(20, 82, 20)},  // Africa
  {strip.Color(120,60,20), strip.Color(200,20,20), strip.Color(120,60,20), strip.Color(200,20,20), strip.Color(120,60,20), strip.Color(200,20,20), strip.Color(120,60,20)}   // Asia
};
uint16_t resorts[5][7] = {
  {strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250)},  // Contemporary Resort (single white rotating)
  {strip.Color(20, 178, 20), strip.Color(20, 82, 20), strip.Color(20, 82, 20), strip.Color(20, 178, 20), strip.Color(20, 178, 20), strip.Color(20, 178, 20), strip.Color(0, 10, 130)},  // Fort Wilderness
  {strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250), strip.Color(250, 250, 250)},  // Transportation and Ticket Center  Do not light up
  {strip.Color(120,60,20), strip.Color(200,20,20), strip.Color(120,60,20), strip.Color(200,20,20), strip.Color(120,60,20), strip.Color(200,20,20), strip.Color(200,20,20)},  // Polynesian
  {strip.Color(240, 60, 60), strip.Color(250, 250, 250), strip.Color(240, 60, 60), strip.Color(250, 250, 250), strip.Color(240, 60, 60), strip.Color(250, 250, 250), strip.Color(240, 60, 60)}   // Grand Floridian
};

void loop(){
  Serial.println("Magic Kingdom");
  for (int i = 0; i < 4; i++){
    for (int e = 0; e < 7; e++){
      strip.setPixelColor((uint16_t)e, magic_kingdom[i][e]);
      Serial.print("Number: ");
      Serial.print(i);
      Serial.print(" Step: ");
      Serial.println(e);
    }
    strip.show();
    delay(500);
  }
    delay(500);
  Serial.println("EPCOT Center");
  for (int i = 0; i < 8; i++){
    for (int e = 0; e < 7; e++){
      strip.setPixelColor((uint16_t)e, epcot_center[i][e]);
      Serial.print("Number: ");
      Serial.print(i);
      Serial.print(" Step: ");
      Serial.println(e);
    }
    strip.show();
    delay(500);
  }
    delay(500);
  Serial.println("Hollywood Studios");
  for (int i = 0; i < 4; i++){
    for (int e = 0; e < 7; e++){
      strip.setPixelColor((uint16_t)e, hollywood_studios[i][e]);
      Serial.print("Number: ");
      Serial.print(i);
      Serial.print(" Step: ");
      Serial.println(e);
    }
    strip.show();
    delay(500);
  }
    delay(500);
  Serial.println("Hotel Set");
  for (int i = 0; i < 6; i++){
    for (int e = 0; e < 7; e++){
      strip.setPixelColor((uint16_t)e, hotel[i][e]);
      Serial.print("Number: ");
      Serial.print(i);
      Serial.print(" Step: ");
      Serial.println(e);
    }
    strip.show();
    delay(500);
  }
    delay(500);
  Serial.println("Animal Kingdom");
  for (int i = 0; i < 5; i++){
    for (int e = 0; e < 7; e++){
      strip.setPixelColor((uint16_t)e, animal_kingdom[i][e]);
      Serial.print("Number: ");
      Serial.print(i);
      Serial.print(" Step: ");
      Serial.println(e);
    }
    strip.show();
    delay(500);
  }
    delay(500);
  Serial.println("Resorts");
  for (int i = 0; i < 5; i++){
    for (int e = 0; e < 7; e++){
      strip.setPixelColor((uint16_t)e, resorts[i][e]);
      Serial.print("Number: ");
      Serial.print(i);
      Serial.print(" Step: ");
      Serial.println(e);
    }
    strip.show();
    delay(500);
  }
    delay(500);
  
}
