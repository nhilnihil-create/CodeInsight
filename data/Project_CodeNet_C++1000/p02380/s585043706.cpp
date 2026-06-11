#include <stdio.h>
#include <math.h>
#define pi 3.14159265358979

int main(void) {
  double a, b, c, d, s;
  scanf("%lf%lf%lf", &a, &b, &c);
  c = c / 180 * pi;
  d = sqrt(a * a + b * b - 2 * a * b * cos(c));
  s = a * b / 2 * sin(c);
  printf("%f\n%f\n%f\n", s, a + b + d, s * 2 / a);
  return 0;
}
