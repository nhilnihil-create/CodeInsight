#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<ll, ll>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (ll i = begin; i < n; i++)
#define repe(i, begin, n) for (ll i = begin; i <= n; i++)
#define repr(i, begin, n) for (ll i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (ll i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const ll inf = 1000000007;
const ll MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

long long modpow(long long a, long long b) {
  a %= MOD;
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

string L;
double eps = 1e-9;

int main() {
  cin >> L;

  ll ans = 0;
  ll pre = 1;
  ll len = L.size();
  rep(i, 0, len) {
    if (L[i] == '1') {
      ans += pre * modpow(3, len - i - 1) % MOD;
      ans %= MOD;
      pre *= 2;
      pre %= MOD;
    }
  }
  ans += pre;
  ans %= MOD;

  cout << ans;
}
