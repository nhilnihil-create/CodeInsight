#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main() {
  int a, b;
  double degree;
  cin >> a >> b >> degree;
  double rad = M_PI*(degree/180);
  double s = a*b*sin(rad)/2;
  printf("%.5lf\n", s);
  double c = a*a + b*b - 2*a*b*cos(rad);
  c = sqrt(c);
  printf("%.5lf\n", a+b+c);
  printf("%.5lf\n", s*2/a);
  return 0;
}