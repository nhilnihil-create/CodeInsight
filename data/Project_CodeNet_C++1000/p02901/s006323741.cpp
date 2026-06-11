#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const int INF = 1 << 30;
int mod = 1000000007;

int main() {
  int N, M;
  cin >> N >> M;
  int state = (1 << N);
  vector<int> dp[M + 1];
  rep(i, M + 1) dp[i].resize(state);

  int A[M], B[M];
  rep(i, M) {
    int a, k;
    cin >> a >> k;
    A[i] = a;
    int acc = 0;
    rep(j, k) {
      int c;
      cin >> c;
      acc += (1 << (c - 1));
    }
    B[i] = acc;
  }

  rep(i, M + 1) rep(j, state) dp[i][j] = INF;
  dp[0][0] = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < state; j++) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      int to = j | B[i];
      dp[i + 1][to] = min(dp[i + 1][to], dp[i][j] + A[i]);
    }
  }
  if (dp[M][state - 1] == INF)
    cout << -1 << endl;
  else
    cout << dp[M][state - 1] << endl;
  return 0;
}
