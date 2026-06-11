#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  double a, b, c, x, t;
  cin >> a >> b >> x;
  
  if(x <= a * a * b / 2) {
    c = 2 * x / (a * b);
    t = atan(b / c);
  } else {
    c = 2 * x / (a * a) - b;
    t = atan((b - c) / a);
  }
  
  cout << fixed << setprecision(10) << 180 * t / M_PI << endl;
  return 0;
}