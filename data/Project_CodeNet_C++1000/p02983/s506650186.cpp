#include <bits/stdc++.h>
#define rep(i,s,n) for (ll i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll l,r;
  cin >> l >> r;
  ll mod = 2019;
  if (l % mod == 0) {
    cout << 0 << endl;
  } else {
    if ((l/mod) * mod + mod <= r) {
      cout << 0 << endl;
    } else {
      ll ans = 1000000000000;
      rep(i,l,r) rep(j,i+1,r+1) {
        ans = min(ans, i*j % mod);
      }
      cout << ans << endl;
    }
  }
  return 0;
}
