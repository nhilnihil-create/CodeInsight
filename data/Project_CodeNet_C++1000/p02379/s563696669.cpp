#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
  double x1, y1, x2, y2, x, y;
  cin >> x1 >> y1 >> x2 >> y2;
  x = abs(x2 - x1);
  y = abs(y2 - y1);
  printf("%f\n", sqrt(x * x + y * y));

  return 0;
}