#include <bits/stdc++.h>
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

using namespace std;

const int MOD = 1e9 + 7;

typedef long long ll;

ll bin_exp(ll a, ll b, ll mod) {
  if (b == 0) {
    return 1;
  }
  ll temp = bin_exp(a, b / 2, mod);
  ll ans;
  if (b % 2 == 0) {
    ans = (temp * temp) % mod;
  } else {
    ans = (temp * temp) % mod;
    ans = (ans * a) % mod;
  }
  return ans;
}

int32_t main() {
  ll n;
  cin >> n;
  ll ans;
  ans = bin_exp(10, n, MOD);  // total
  ans -= bin_exp(9, n, MOD);  // without 1
  ans = (ans + MOD) % MOD;
  ans -= bin_exp(9, n, MOD);  // without 0
  ans = (ans + MOD) % MOD;
  ans += bin_exp(8, n, MOD);  // without both 0 and 1
  ans = (ans + MOD) % MOD;
  cout << ans << '\n';
  return 0;
}
