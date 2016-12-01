#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "shape.h"

AbRect swShape = {abRectGetBounds, abRectCheck, 5,150};
AbRect rect = {abRArrowGetBounds, abRectCheck, 10, 10};
AbRArrow arrow = {abRArrowGetBounds, abRArrowCheck, 30};

Region fence = {{10,30}, {SHORT_EDGE_PIXELS-10, LONG_EDGE_PIXELS-10}};

Layer car1 = {
  (AbShape *)&rect,
  {50,20},
  {0,0}, {0,0},				    /* last & next pos */
  COLOR_BLUE,
  0,
};
Layer sidewalkL = {
  (AbShape *)&swShape,
  {screenWidth-120, screenHeight-10},
  {0,0}, {0,0},
  COLOR_RED,
  &car1,
};
Layer sidewalkR = {
  (AbShape *)&swShape,
  {screenWidth-5, screenHeight-10},
  {0,0}, {0,0},				   
  COLOR_RED,
  &sidewalkL,
};

typedef struct MovLayer_s {
  Layer *layer;
  Vec2 velocity;
  struct MovLayer_s *next;
} MovLayer;

MovLayer ml0 = { &car1, {1,1}, 0};


u_int bgColor = COLOR_BLACK;

main()
{
  configureClocks();
  lcd_init();
  shapeInit();
  Vec2 rectPos = screenCenter, circlePos = {30,screenHeight - 30};

  clearScreen(COLOR_BLACK);
  shapeInit();
  
  layerInit(&sidewalkR);
  layerDraw(&sidewalkR);
  int i = 0;
  for(;;){
    drawString5x7(20,20, "DodgeRacer", COLOR_GREEN, COLOR_RED); 
    Vec2 newPos = {55,100};
    car1.pos = newPos;
    layerInit(&car1);
    layerDraw(&car1);
    i+=10;
  }
  
}


