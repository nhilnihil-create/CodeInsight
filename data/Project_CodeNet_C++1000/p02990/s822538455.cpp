#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;

ll pow_mod(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res *= a;
    a = a*a;
    a %= mod;
    n >>= 1;
    res %= mod;
  }
  return res;
}

ll inv(ll x, ll mod) {
  ll res = pow_mod(x, mod - 2, mod);
  return res;
}

ll comb_mod(ll n, ll r, ll mod) {
  ll res;
  ll x = 1, y = 1;
  for (ll i = 0; i < r; i++) {
    x *= n-i;
    x %= mod;
    y *= r-i;
    y %= mod;
  }
  res = x * inv(y, mod);
  res %= mod;
  return res;
}

int main() {
  ll N, K;
  cin >> N >> K;
  for (ll i = 0; i < K; i++) {
    ll ans = 0;
    if (i > N-K) {
      cout << 0 << endl;
    }
    else {
      ans = comb_mod(K-1, i, mod) * comb_mod(N-K+1, i+1, mod);
      ans %= mod;
      cout << ans << endl;
    }
  }
}