#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  int a, b, x;
  cin >> a >> b >> x;

  double ans;

  if (x <= 0.5 * b * a * a) {
    double h = x / (0.5*a*b);
    ans = atan(b / h) * 180 / M_PI;
  } else {
    int remainder = a*a*b - x;
    double h = remainder / (0.5*a*a);
    ans = atan(h / a) * 180 / M_PI;
  }

  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}