#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  // double e = d * 6.0;
  // double f = c * 30.0 + d * 0.5;
  double g = (c * 30.0 - d * 5.5) * acos(-1) / 180.0;
  cout << fixed << setprecision(10)
       << sqrt(a * a + b * b - 2.0 * a * b * cos(g)) << '\n';
  return 0;
}
