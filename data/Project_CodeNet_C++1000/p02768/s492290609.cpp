#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#define REP(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using arr = vector<ll>;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

ll n, a, b;

ll modpow(ll x, ll e) {
  ll res = 1;
  while(e) {
    if (e & 1) res = res * x % MOD;
    x = x * x % MOD;
    e >>= 1;
  }
  return res;
}

ll comb(ll n, ll k) {
  ll res = 1;
  REP(i, k) {
    res = res * (n - i) % MOD * modpow(i + 1, MOD - 2) % MOD;
  }
  return res;
}

int main()
{
  cin >> n >> a >> b;

  ll ans = modpow(2, n) - 1;
  ans = (ans + MOD - comb(n, a)) % MOD;
  ans = (ans + MOD - comb(n, b)) % MOD;
  cout << ans;
  return 0;
}