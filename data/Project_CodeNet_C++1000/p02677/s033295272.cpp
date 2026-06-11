#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
const long long MOD = 1000000007;
const double PI = 3.1415926535;

int main(void) {
  double a, b, h, m;
  cin >> a >> b >> h >> m;

  if (h == 0 && m == 0) {
    cout << abs(a-b) << endl;
    return 0;
  }

  //短針
  double argh = h * 30 + m * 0.5;
  //長針
  double argm = m * 6;

  double rad;
  //短針を追い越さない時
  if (argh > argm) {
    rad = (argh - argm) / 180.0 * PI;
  } else
    rad = (argm - argh) / 180.0 * PI;
  double ans = pow(a * a + b * b - 2 * a * b * cos(rad), 0.5);
  printf("%0.9lf\n", ans);
  return 0;
}
