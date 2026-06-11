#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int main(){
  double a, b, c;
  double rad;
  double l; //third line length
  double S, L, h;

  scanf("%lf %lf %lf", &a, &b, &c);

  rad=c*PI/180.0;
  S=a*b*(sin(rad))/2;
  l=sqrt(a*a+b*b-2*a*b*cos(rad));
  L=a+b+l;
  h=S*2/a;

  printf("%.6f\n", S);
  printf("%.6f\n", L);
  printf("%.6f\n", h);

  return 0;
}