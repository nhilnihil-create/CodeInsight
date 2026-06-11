#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
using ld = long double;

constexpr ld rad2pi = 180.l / 3.14159265359l;
int main() {
  ld a, b, x, ans;
  cin >> a >> b >> x;
  if (x < a * a * b / 2) {
    ans = atan(a * b * b / 2 / x) * rad2pi;
  } else {
    ans = atan(2 * b / a - 2 * x / a / a / a) * rad2pi;
  }
  cout << fixed << setprecision(10) << ans << endl;
}
