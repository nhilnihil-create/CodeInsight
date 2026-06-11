#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) {
  if (a % b == 0) return b;
  else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  ll d = gcd(a, b);
  return a * b / gcd(a, b);
}

int main() {
  ll a, b; cin >> a >> b;
  ll c, d; cin >> c >> d;
  a--;
  // a~bにおける
  // c の倍数の個数
  ll cn = (b / c - a / c);
  // d の倍数の個数
  ll dn = (b / d - a / d);
  // c,d の公倍数の個数
  ll cdn = (b / lcm(c,d) - a / lcm(c,d));
  ll ans = (b - a) - (cn + dn - cdn);
  cout << ans << endl;

  return 0;
}