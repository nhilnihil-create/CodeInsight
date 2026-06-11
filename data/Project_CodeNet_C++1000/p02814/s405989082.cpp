#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MAX = 1e9;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

ll solve(ll n, ll m, vector<ll> &a) {
  bool same = true;
  while (a[0] % 2 == 0) {
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 != 0) {
        return 0;
      }
      a[i] /= 2;
    }
    m /= 2;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      return 0;
    }
  }
  ll v = 1;
  for (int i = 0; i < n; i++) {
    v = lcm(v, a[i]);
    if (v > m) {
      return 0;
    }
  }
  return (m / v + 1) / 2;
}

// (ai/2 * (2p + 1))に変形できる
// 奇数はかけれるが偶数はかけれない
// 任意のai, akで2の約数の数が異なった場合はNG
// そうでない場合は同じ値にできる
int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] /= 2;
  }
  cout << solve(n, m, a) << endl;
}
