#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b); 
}

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll ans = b - a + 1;
  ans -= b / c - (a - 1) / c;
  ans -= b / d - (a - 1) / d;
  ll l = lcm(c, d);
  ans += b / l - (a - 1) / l;
  cout << ans << endl;
  return 0;
}