#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int dp[2000][5000];
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int main() {
  int N, M;
  cin >> N >> M;
  memset(dp, INF, sizeof(dp));
  vector<int> a(M), b(M), c(M);
  REP(i, M) {
    cin >> a[i] >> b[i];
    REP(j, b[i]) {
      int t;
      cin >> t, t--;
      c[i] += 1 << t;
    }
  }
  REP(i, 2000) REP(j, 5000) dp[i][j] = INF;
  dp[0][0] = 0;
  REP(i, M) {
    REP(j, 1 << N) {
      chmin(dp[i + 1][j], dp[i][j]);
      int n = j | c[i];
      chmin(dp[i + 1][n], dp[i][j] + a[i]);
    }
  }
  cout << (dp[M][(1 << N) - 1] == INF ? -1 : dp[M][(1 << N) - 1]) << endl;
}