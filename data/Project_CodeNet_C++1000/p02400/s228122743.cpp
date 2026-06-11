#include <stdio.h>
int main (void){
  double r;
  scanf("%lf",&r);
  double pai;
  pai=3.141592653589;
  double x;
  x=r*r*pai;
  double y;
  y=r*2*pai;
  printf("%f %f\n",x,y);
  return 0;
}