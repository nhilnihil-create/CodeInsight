#include <iostream>
#include <cstdio>
#include <cmath>
#define PI 3.14159265


int main(){
  double a, b, C;
  std::cin >> a >> b >> C;

  double theta = C * PI / 180.0;
  double S, c, L, h;

  S = a * b * sin(theta) / 2;

  c = sqrt(a*a + b*b - 2*a*b*cos(theta));
  L = a + b + c;

  h = 2 * S / a; // S = 1/2 * a * h

  printf("%.8lf\n%.8lf\n%.8lf\n", S, L, h);
}

