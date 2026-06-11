#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod = 1000000007;

ll modpow(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  ll ans = modpow(10, n) - 2*modpow(9, n) + modpow(8, n);
  ans %= mod;
  ans = (ans + mod) % mod;
  cout << ans << endl;
}