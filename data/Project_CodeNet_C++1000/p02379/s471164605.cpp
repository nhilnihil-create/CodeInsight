#include <algorithm>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;
int main(void) {
  cout << fixed << setprecision(12);
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double xx, yy;
  xx = abs(x1 - x2);
  yy = abs(y1 - y2);
  cout << sqrt(pow(xx,2)+pow(yy,2)) << endl;

  return 0;
}


