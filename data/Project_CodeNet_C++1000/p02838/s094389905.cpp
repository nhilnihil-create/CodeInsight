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

ll N;
ll cnt[100];

int main() {
  cin >> N;
  rep(i, 0, N) {
    ll a;
    cin >> a;
    rep(i, 0, 60) {
      if (a & (1LL << ll(i))) ++cnt[i];
    }
  }

  ll ans = 0;
  ll base = 1;
  rep(i, 0, 60) {
    ll ccnt = cnt[i] * (N - cnt[i]) % MOD;
    ans += base * ccnt % MOD;
    ans %= MOD;

    base *= 2;
    base %= MOD;
  }

  cout << ans;
}
