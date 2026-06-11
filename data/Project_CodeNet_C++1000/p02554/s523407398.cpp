#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;

ll powmod(ll x, ll y) {
  ll res = 1;
  for (ll i = 0; i < y; i++) res = res * x % mod;
  return res;
}

int main(void) {
  int n;
  cin >> n;
  ll ans = 0;
  ans = powmod(10, n) - powmod(9, n) - powmod(9, n) + powmod(8, n);
  ans %= mod;
  ans = (ans + mod) % mod;
  cout << ans << '\n';
  return 0;
}