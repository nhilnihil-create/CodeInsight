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

ll N, M;
ll a[1010], b[1010];
vector<ll> c[1010];
ll dp[1010][10000];

int main() {
  cin >> N >> M;
  rep(i, 0, M) {
    cin >> a[i] >> b[i];
    c[i].resize(b[i]);
    rep(j, 0, b[i]) { cin >> c[i][j]; }
  }

  rep(i, 0, 1010) {
    rep(j, 0, (1 << N)) { dp[i][j] = INF; }
  }
  dp[0][0] = 0;

  repe(i, 1, M) {
    ll mask = 0;
    for (auto e : c[i - 1]) {
      mask |= (1 << (e - 1));
    }
    for (ll bit = 0; bit < (1 << N); ++bit) {
      dp[i][bit] = dp[i - 1][bit];
    }
    for (ll bit = 0; bit < (1 << N); ++bit) {
      chmin(dp[i][mask | bit], dp[i - 1][bit] + a[i - 1]);
    }
  }

  ll all = (1 << N) - 1;

  if (dp[M][all] == INF) {
    cout << -1;
  } else {
    cout << dp[M][all];
  }
}
