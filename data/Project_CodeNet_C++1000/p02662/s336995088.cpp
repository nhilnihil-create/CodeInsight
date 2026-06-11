#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (ll i = begin; i < n; i++)
#define repe(i, begin, n) for (ll i = begin; i <= n; i++)
#define repr(i, begin, n) for (ll i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (ll i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const ll inf = 1000000007;
// const ll MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
const ll MOD = 998244353;
ll dp[3030][3030];
ll N;
ll S;
ll A[3030];

int main() {
  cin >> N >> S;
  repe(i, 1, N) { cin >> A[i]; }

  dp[0][0] = 1;
  repe(i, 1, N) {
    ll a = A[i];
    repe(j, 0, S) {
      if (j < a) {
        dp[i][j] = dp[i - 1][j] * 2;
        dp[i][j] %= MOD;
      } else {
        dp[i][j] = dp[i - 1][j] * 2 + dp[i - 1][j - a];
        dp[i][j] %= MOD;
      }
    }
  }
  cout << dp[N][S] << endl;
}
