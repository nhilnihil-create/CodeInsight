#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int INF = 1e9;

signed main(){
  int N, M; cin >> N >> M;
  vector<int> cost(M);
  vector<int> type(M, 0);
  for(int i = 0; i < M; i++){
    int t; cin >> cost[i] >> t;
    for(int j = 0; j < t; j++){
      int x; cin >> x; type[i] += (1 << (x - 1));
    }
  }
  vector<vector<int> > dp(M + 1, vector<int> (1 << N, INF));
  dp[0][0] = 0;
  for(int i = 0; i < M; i++){
    for(int j = 0; j < (1 << N); j++){
      dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
      dp[i + 1][j | type[i]] = min(dp[i + 1][j | type[i]], dp[i][j] + cost[i]);
    }
  }
  int ans = dp[M][(1 << N) - 1];
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
}