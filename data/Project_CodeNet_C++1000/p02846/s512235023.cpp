#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll t1, t2;
  cin >> t1 >> t2;

  ll a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;

  ll p = (a1 - b1) * t1;
  ll q = (a2 - b2) * t2;
  if (p > 0) {
    p *= -1;
    q *= -1;
  }

  if (p + q < 0) {
    cout << 0 << '\n';
    return 0;
  } else if (p + q == 0) {
    cout << "infinity" << '\n';
    return 0;
  }

  ll s, t;
  s = -p / (p + q);
  t = -p % (p + q);

  if (t != 0) {
    cout << s * 2 + 1 << '\n';
  } else {
    cout << s * 2 << '\n';
  }

  return 0;
}