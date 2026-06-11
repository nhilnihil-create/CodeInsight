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
ll S[2010], T[2010];
ll dp[2010][2010];
ll cum[2010][2010];

int main() {
  cin >> N >> M;
  rep(i, 0, N) { cin >> S[i]; }
  S[N] = -1;
  rep(i, 0, M) { cin >> T[i]; }
  T[M] = -1;

  dp[0][0] = 1;
  cum[0][0] = dp[0][0];
  repe(i, 1, N) { cum[i][0] = cum[i - 1][0]; }
  repe(i, 1, M) { cum[0][i] = cum[0][i - 1]; }

  repe(i, 0, N) {
    repe(j, 0, M) {
      if (S[i] != T[j]) {
        dp[i + 1][j + 1] = 0;
      } else {
        dp[i + 1][j + 1] = cum[i][j];
      }
      cum[i + 1][j + 1] =
          dp[i + 1][j + 1] + cum[i + 1][j] + cum[i][j + 1] - cum[i][j] + MOD;
      cum[i + 1][j + 1] %= MOD;
    }
  }

  cout << dp[N + 1][M + 1];
}
