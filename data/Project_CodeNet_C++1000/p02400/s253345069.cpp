#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;
int main() {
  double r, s, p;
  cin >> r;
  s = r * r * M_PI;
  p = (r * 2) * M_PI;
  printf("%.6f %.6f\n", s, p);
  return 0;
}