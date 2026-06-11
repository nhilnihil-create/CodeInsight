#include <stdio.h>
#include <math.h>

#define PI 3.141592653589

double distance(double x1, double y1, double x2, double y2);

int main(void){
  double a, b, c, s, l, h;

  scanf("%lf%lf%lf", &a, &b, &c);
  h = b * sin(PI * c / 180);
  l = a + b + distance(a, 0, b * cos(PI * c / 180), b * sin(PI * c / 180));
  s = a * h / 2;
  printf("%f\n%f\n%f\n", s, l, h);
  return 0;
}


double distance(double x1, double y1, double x2, double y2){
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1- y2));
}