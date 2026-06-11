#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MOD = 1e9+7;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  rep(i, n) ans = (ans + a[i]) % MOD;
  ans = ans * (n-1) % MOD;

  vector<ll> bc(60, 0);
  rep(i, n) rep(bi, 60) {
    if (a[i] & 1LL<<bi) ++bc[bi];
  }
  rep(bi, 60) {
    ans = ((ans - bc[bi] * (bc[bi]-1) % MOD * ((1LL<<bi) % MOD)) % MOD) % MOD;
  }
  if (ans < 0) ans += MOD;
  cout << ans << endl;
  return 0;
}