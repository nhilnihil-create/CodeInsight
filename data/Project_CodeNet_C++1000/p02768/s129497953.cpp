#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const ll MOD = 1e9 + 7;

ll modpow(ll a, ll n) {
  ll ret = 1;
  while (n > 0) {
    if (n & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return ret;
}
ll modinv(ll a) { return modpow(a, MOD - 2); }

ll comb(ll n, ll r) {
  ll ret = 1;
  for (ll i = 0; i < r; i++) ret = ret * (n - i) % MOD;
  for (ll i = 1; i <= r; i++) ret = ret * modinv(i) % MOD;
  return ret;
}

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  ll ans = modpow(2, n);
  ans -= 1;
  if (ans < 0) ans += MOD;
  ans -= comb(n, a);
  if (ans < 0) ans += MOD;
  ans -= comb(n, b);
  if (ans < 0) ans += MOD;

  cout << ans << endl;
}
