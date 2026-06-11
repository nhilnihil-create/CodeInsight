#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  double a, b, x; cin >> a >> b >> x;

  double s = x / a;
  double theta;

  if (s * 2 <= a * b) {
    // At the maximum tilt, a triangle forms
    theta = atan((b * b) / (2 * s));
  } else {
    // At the maximum tilt, a quadrilateral forms
    theta = atan(2 * (a * b - s) / (a * a));
  }

  double ans = theta * 180 / M_PI;

  cout << setprecision(10) << ans << endl;
}