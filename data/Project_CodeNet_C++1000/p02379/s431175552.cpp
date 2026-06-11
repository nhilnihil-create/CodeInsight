#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int main() {
  long double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
	printf("%Lf\n", sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)));
  return 0;
}