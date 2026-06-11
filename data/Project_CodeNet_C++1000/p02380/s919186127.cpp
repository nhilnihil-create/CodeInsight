#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793
int main(void)
{
  int a,b;
  double C,c, S, L, h;
  scanf("%d%d%lf", &a, &b, &C);
  C = C*PI/180.0;
  S = (double)a * (double)b * sin(C) / 2;
  c = sqrt(a*a+b*b-2*a*b*cos(C));
  L = a + b + c;
  h = b*sin(C);
  printf("%lf\n%lf\n%lf\n",S,L,h);


  return 0;
}