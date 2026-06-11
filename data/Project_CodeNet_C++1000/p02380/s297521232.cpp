#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
  double a, b, C, S, L, h;
  cin >> a >> b >> C;
  h = b * sin(C * M_PI / 180);
  S = a * h / 2;
  L = a + b + sqrt(a * a + b * b - 2 * a * b * cos(C * M_PI / 180));
  printf("%f\n", S);
  printf("%f\n", L);
  printf("%f\n", h);

  return 0;
}