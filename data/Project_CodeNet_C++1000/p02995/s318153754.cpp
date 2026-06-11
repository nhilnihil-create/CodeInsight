#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll total = b - a + 1;
  ll cd = lcm(c, d);
  ll mula = b / c - a / c;
  if (a % c == 0) {
    mula += 1;
  }

  ll mulb = b / d - a / d;
  if (a % d == 0) {
    mulb += 1;
  }

  ll mulc = b / cd - a / cd;
  if (a % cd == 0) {
    mulc += 1;
  }
  ll k = mula + mulb - mulc;
  cout << total - k << endl;
  return 0;
}
