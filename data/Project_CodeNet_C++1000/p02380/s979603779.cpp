#include <cmath>
#include <cstdio>

int main() {
  int a, b, C;
  scanf("%d%d%d", &a, &b, &C);

  const double PI = 3.141592653589;
  double S = a * b * sin(C * PI / 180) / 2;
  double L = a + b + sqrt(a * a + b * b - 2 * a * b * cos(C * PI / 180));
  double h = S * 2 / a;

  printf("%f %f %f\n", S, L, h);

  return 0;
}
