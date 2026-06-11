#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

const int mod = 1000000007;

ll modpow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n % 2 == 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

ll modinv(ll x) { return modpow(x, mod - 2); }

// nCk
ll modfact(ll n, int k) {
  ll ret = 1, m = n % mod;
  rep(i, k) {
    ret *= m % mod;
    ret %= mod;
    --m;
  }
  return ret;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  ll ans = modpow(2, n) - 1;

  ll fa = modfact(a, a);
  ll ifa = modpow(fa, mod - 2);

  ll fb = modfact(b, b);
  ll ifb = modpow(fb, mod - 2);

  ans -= modfact(n, a) * ifa % mod;
  ans = (ans + mod) % mod;
  ans -= modfact(n, b) * ifb % mod;
  ans = (ans + mod) % mod;

  cout << ans << '\n';
  return 0;
}
