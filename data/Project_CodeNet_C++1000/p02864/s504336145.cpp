#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1LL<<62

int N, K;
int H[300];

int dp[300][300];

signed main() {
  cin >> N >> K;
  for (int i=0; i<N; i++) cin >> H[i];

  dp[0][0] = H[0];

  for(int r=1; r < N; r++) dp[r][0] = H[r];
  for(int ncol=1; ncol < N; ncol++) dp[0][ncol] = INF;

  for(int r=1; r < N; r++) for(int ncol=1; ncol < N-K; ncol++) {
    int v = INF;
    for (int i=0; i<r; i++) v = min(v, dp[i][ncol-1] + max(0LL, H[r] - H[i]));
    dp[r][ncol] = v;
  }

  int ans = INF;
  for (int i=0; i<N; i++) ans = min(ans, dp[i][N-K-1]);

  cout << ans << endl;

  return 0;
}
