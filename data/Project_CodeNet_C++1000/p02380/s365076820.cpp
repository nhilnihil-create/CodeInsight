#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
  double a, b, c, C, S, L, h;
  cin >> a >> b >> C;
  C = C * M_PI / 180;
  S = a * b * sin(C) / 2;
  c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(C));
  L = a + b + c;
  h = b * sin(C);
  printf("%.8f\n%.8f\n%.8f\n", S, L, h);
}