#include <stdio.h>
#include <math.h>

int main(void)
{
  double r, s, l;

  scanf("%lf", &r);

  s = M_PI*r*r;
  l = 2.0*M_PI*r;

  printf("%.6lf %.6lf\n", s, l);

  return 0;
}