#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  double r;
  cin >> r;

  const double a =  M_PI * r * r;
  const double l = 2 * M_PI * r;
  printf("%f %f\n", a, l);
  return 0;
}