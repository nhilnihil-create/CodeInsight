#include <iostream>

using namespace std;
using ll = long long;

ll mod = 1000000007;

ll modinv(ll a) {
  ll n = mod - 2;
  ll res = 1;
  while (0 < n) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  ll x, y;
  cin >> x >> y;
  ll a = (2 * y - x) / 3;
  ll b = y - 2 * a;

  ll res = 0 <= a && 0 <= b && a + 2 * b == x && 2 * a + b == y;
  for (ll i = 0; i < a + b; ++i)
    res = res * (a + b - i) % mod;
  for (ll i = 0; i < a; ++i)
    res = res * modinv(a - i) % mod;
  for (ll i = 0; i < b; ++i)
    res = res * modinv(b - i) % mod;
  cout << res << endl;
}