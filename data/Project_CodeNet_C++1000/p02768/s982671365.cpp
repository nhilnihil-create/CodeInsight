#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MOD = 1e9 + 7;
const int N = 2e5;

ll modpow(ll a, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1; 
  }
  return res;
}

ll modinv(ll a) {
  ll b = MOD, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= MOD;
  if (u < 0) u += MOD;
  return u;
}

ll modcomb(ll n, ll k) {
  ll res = 1;
  rep(i, k) res = res * (n-i) % MOD;
  rep(i, k) res = res * modinv(i+1) % MOD;
  return res;
}

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = (modpow(2, n) - 1) % MOD;
  ans = (ans - modcomb(n, a)) % MOD;
  ans = (ans - modcomb(n, b)) % MOD;
  if (ans < 0) ans += MOD;
  cout << ans << endl;
  return 0;
}