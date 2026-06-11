#include <stdio.h>
#include <math.h>

int main(void) {
  double a, b, c, d;
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
  printf("%f\n", sqrt((a - c) * (a - c) + (b - d) * (b - d)));
  return 0;
}
