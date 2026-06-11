#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
  while (b) {
    ll c = b;
    b = a % b;
    a = c;
  }
  return a;
}

ll lcm(ll a, ll b) {
  if (!a || !b) return 0;
  return a * b / gcd(a, b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll ans = b - a + 1;
  ans -= b / c - (a - 1) / c;
  ans -= b / d - (a - 1) / d;
  ans += b / lcm(c, d) - (a - 1) / lcm(c, d);
  cout << ans << '\n';
  return 0;
}
