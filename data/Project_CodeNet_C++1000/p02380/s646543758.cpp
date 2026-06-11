#include <stdio.h>
#include <math.h>

int main(void)
{
  double a,b,C,c;
  double S,L,h;
  double d; //??????
  double si,co;
  double pai = 3.1415926;
  
  scanf("%lf%lf%lf",&a,&b,&C);

  c = C / 180 *pai;
  si = sin(c);
  co = cos(c);
  h = b * si;
  d = sqrt((a*a)+(b*b)-(2*a*b*co));
  L = a+b+d;
  S = (a * h) / 2;

  printf("%f\n%f\n%f\n",S,L,h);
  
  return(0);
}