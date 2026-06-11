#include<bits/stdc++.h>
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<int>(a); i < static_cast<int>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
#define chmax(x, a)  do { x = max(x, a); } while(0)
#define chmin(x, a)  do { x = min(x, a); } while(0)

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll,ll> PLL;

void solve() {
  ll x,k,d;
  cin >> x >> k >> d;
  if (x < 0)
    x *= -1;

  ll t = min(k, (x - d + d - 1)/ d);
  k -= t;
  x -= d * t;

  ll ans;
  if ((k % 2) == 0) {
    ans = x;
  } else {
    ans = abs(x-d);
  }
  cout << ans << endl;
}

int main() {
  //ll T;
  //cin >> T;
  //rep(_,T)
    solve();
  return 0;
}
