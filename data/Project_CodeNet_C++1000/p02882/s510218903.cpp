#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  double a, b, x;
  cin >> a >> b >> x;
  x /= a;
  const double PI = acos(-1.0);
  cout << fixed << setprecision(10);
  if (x > a * b / 2) {
    cout << atan2(2 * (a * b - x), a * a) * 180 / PI << endl;
  } else {
    cout << atan2(b * b, 2 * x) * 180 / PI << endl;
  }
  return 0;
}