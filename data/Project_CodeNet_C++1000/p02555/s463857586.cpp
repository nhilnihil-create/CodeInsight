
// Problem : D - Redistribution
// Contest : AtCoder - AtCoder Beginner Contest 178
// URL : https://atcoder.jp/contests/abc178/tasks/abc178_d
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

typedef long long ll;

const ll MOD = 1e9 + 7;

ll modulo(ll a, ll b, ll n) {
  ll x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % n;  // multiplying with base
    }
    y = (y * y) % n;  // squaring the base
    b /= 2;
  }
  return x % n;
}

using namespace std;

ll factorial[50001];

void pre() {
  factorial[0] = 1;
  for (ll i = 1; i <= 50000; i++) {
    factorial[i] = (factorial[i - 1] * i) % MOD;
  }
}

ll mod_inv(ll x) { return modulo(x, MOD - 2, MOD) % MOD; }

ll nCr(ll n, ll r) {
  if (n < r) return 0;
  ll ans = factorial[n];
  ans = ans * mod_inv((factorial[r] * factorial[n - r]) % MOD);
  ans = ans % MOD;
  return ans;
}

int32_t main() {
  ll s;
  cin >> s;
  ll ans = 0;
  pre();
  for (ll len = 1; len <= s / 3; len++) {
    ll sum = s - 3 * len;
    if (sum >= 0) ans = (ans + nCr((sum + len - 1), (len - 1))) % MOD;
  }

  cout << ans << '\n';
  return 0;
}
