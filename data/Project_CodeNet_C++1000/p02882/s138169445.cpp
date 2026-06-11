#include <iostream>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265359

using namespace std;

int main() {
  double a, b, x;
  cin >> a >> b >> x;
  double res;
  if (x <= 0.5 * a * a * b) {
    res = atan(2.0 * x / (a * b * b));
  } else {
    res = atan(a / (2.0 * (b - x / (a * a))));
  }
  printf("%.7f\n", 90 - res * 180 / PI);
}