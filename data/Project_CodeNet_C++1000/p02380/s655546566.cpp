#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

inline double radian(int C) {
  return C * M_PI / 180.0;
}

inline double area(int a, int b, double theta) {
  return 0.5 * a * b * sin(theta);
}

inline double calc_L(int a, int b, double theta) {
  // law of cosines                                                                                                                                                       
  const double c =
      sqrt(static_cast<double>(a * a + b * b) - 2.0 * a * b * cos(theta));
  return a + b + c;
}

inline double height(int a, double S) {
  return 2.0 * S / static_cast<double>(a);
}

int main() {
  int a, b, C;

  cin >> a >> b >> C;

  const double theta = radian(C);
  const double S = area(a, b, theta);
  printf("%.8f\n", S);
  printf("%.8f\n", calc_L(a, b, theta));
  printf("%.8f\n", height(a, S));

  return 0;
}