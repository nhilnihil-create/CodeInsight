#include<iostream>
#include<cmath>
#include<string>
#include<cstdio>

using namespace std;

int main() {
  double a, b, C;
  cin >> a >> b >> C;
  C = C * M_PI / (double)180;

  double S = (double)1/(double)2 * a * b* (double)sin(C);
  double L = a + b + (double)sqrt(pow(a, 2) + pow(b, 2) - ((2 * a *b * (double)cos(C))));
  double h = (double)b * (double)sin(C);

  printf("%0.5f\n", S);
  printf("%0.5f\n", L);
  printf("%0.5f\n", h);



}