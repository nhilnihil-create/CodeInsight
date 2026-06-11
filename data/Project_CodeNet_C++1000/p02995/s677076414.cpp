#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

template <typename T>
T gcd(T a, T b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

template <typename T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  ll all = b - a + 1;

  a--;
  ll div_c = b / c - a / c;
  ll div_d = b / d - a / d;
  ll cd = lcm(c, d);
  ll div_cd = b / cd - a / cd;

  ll ans = all - div_c - div_d + div_cd;
  cout << ans << endl;
}
