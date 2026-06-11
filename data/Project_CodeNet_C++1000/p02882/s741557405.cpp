#include <bits/stdc++.h>
using namespace std;

int main() {
  double pi = 3.141592653;
  double a, b, x;
  cin >> a >> b >> x;
  if(2 * x >= a * a * b) {
    double ans = atan((2 * a * a * b - 2 * x) / (a * a * a));
    ans *= 180;
    ans /= pi;
    cout << fixed << setprecision(7) << ans << endl;
  }
  else {
    double ans = atan((a * b * b) / (2 * x));
    ans *= 180;
    ans /= pi;
    cout << fixed << setprecision(7) << ans << endl;
  }
}