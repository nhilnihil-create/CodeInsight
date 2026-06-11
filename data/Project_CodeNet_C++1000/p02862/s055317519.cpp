#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

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

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

const int MAX = 1010101;

long long fac[MAX], finv[MAX], inv[MAX];

void binom_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long binom(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long perm(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * finv[n - k] % MOD;
}

ll X, Y;

int main() {
  cin >> X >> Y;

  if (Y > X) {
    swap(X, Y);
  }

  if (X == 0 && Y == 0) {
    cout << 1;
    return 0;
  }

  if ((X + Y) % 3 != 0) {
    cout << 0;
    return 0;
  }

  binom_init();

  ll sum = X + Y;
  ll rank = sum / 3;
  ll diff = X - Y;

  if (abs(diff) > rank) {
    cout << 0;
    return 0;
  }

  if (rank % 2 == 0) {
    ll mid = rank / 2;
    cout << binom(rank, mid - abs(diff) / 2);
  } else {
    ll mid = rank / 2;
    cout << binom(rank, mid - diff / 2);
  }
}
