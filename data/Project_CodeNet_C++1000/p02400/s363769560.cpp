#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  double r, S, C, pi=3.141592653589;

  cin >> r;
  S = r*r*pi;
  C = 2*r*pi;

  printf("%.6lf %.6lf", S, C);
  return 0;
}