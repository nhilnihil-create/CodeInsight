#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  double r;
  double circumference, area;

  cin >> r;

  circumference = r * r * M_PI;
  area = 2 * M_PI * r;

  printf("%lf %lf\n", circumference, area);
}