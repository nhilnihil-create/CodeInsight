#include <iostream>

using namespace std;
using ll = long long;

ll mod = 1000000007;

ll modinv(ll a) {
  ll b = mod - 2;
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

ll modmul(ll a, ll b) {
  return a * b % mod;
}

ll modadd(ll a, ll b) {
  return (a + b) % mod;
}

ll modsub(ll a, ll b) {
  ll res = (a - b) % mod;
  return (res < 0) ? res + mod : res;
}

ll hoge(ll x) {
  ll res = modmul(modmul(modinv(2), x), x + 1) - x;
  return (res < 0) ? res + mod : res;
}

int main() {
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  for (int i = k; i <= n+1; ++i)
    ans = modadd(modsub(modsub(modadd(ans, hoge(n+1)), hoge(n-i+1)), hoge(i)), 1);
  cout << ans << endl;
}