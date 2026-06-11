#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

inline double rad(int C) {
  return C * M_PI / 180.0;
}

static double calc_area(int a, int b, double radc) {
  return static_cast<double>(a) * static_cast<double>(b) * sin(radc) / 2.0;
}

static double calc_c(int a, int b, double radc) {
  return sqrt(a * a + b * b - 2 * a * b * cos(radc));
}

static double calc_height(int b, double radc) {
  return b * sin(radc);
}

int main() {
  int a, b, C;
  cin >> a >> b >> C;
  const double radc = rad(C);
  printf("%f\n", calc_area(a, b, radc));
  printf("%f\n", static_cast<double>(a) + static_cast<double>(b) + calc_c(a, b, radc));
  printf("%f\n", calc_height(b, radc));
  return 0;
}