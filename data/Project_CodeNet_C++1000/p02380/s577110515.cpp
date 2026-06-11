#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
  int a, b, c;
  double rad, s, l, h;
  scanf("%d %d %d", &a, &b, &c);
  
  rad = c * M_PI / 180.0; 
  s = 1 / 2.0 * a * b * sin(rad);
  l = a + b + sqrt(a * a + b * b - 2 * a * b * cos(rad));
  h = s * 2.0 / a;
  
  printf("%lf\n%lf\n%lf\n", s, l, h);
  return (0);
}