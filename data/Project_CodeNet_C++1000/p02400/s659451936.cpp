#include <stdio.h>
#include <math.h>
#define PI 4 * atan(1)

int main(void){
  double r;
  scanf("%lf",&r);
  printf("%f %f\n",PI * r * r,2 * PI * r);
  return 0;
}