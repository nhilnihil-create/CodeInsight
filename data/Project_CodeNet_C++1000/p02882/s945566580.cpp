#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  double a, b, x;
  cin >> a >> b >> x;
  double s = x / a;
  double rad;
  if (a * b / 2 <= s) {
    double h = (a * b - s) * 2 / a;
    rad = atan2(h, a);
  } else {
    double w = s * 2 / b;
    rad = atan2(b, w);
  }
  double deg = rad / (2 * M_PI) * 360;
  cout << fixed << setprecision(10) << deg << endl;
  return 0;
}