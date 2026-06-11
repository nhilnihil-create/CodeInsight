#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
  double a, b, C;
  double S, L, h;
  cin >> a >> b >> C;

  double D = acos(-1.0) * C /180.0;
  S = a * b * sin(D) / 2.0;
  L = a + b + sqrt(a*a + b*b -2*a*b*cos(D));
  h = b*sin(D);

  printf("%lf\n%lf\n%lf\n",S, L, h);

  return 0;
}