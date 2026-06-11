#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i, n) for(int (i)=0; (i)< (n); ++i)
#define REPR(i, n) for(int (i)=(n); (i)>=0; --i)
#define FOR(i, n, m) for(int (i)=(n); (i)<(m); ++i)
constexpr int INF = 1e9;
//constexpr ll INF = 1LL << 62;
constexpr int mod = 1e9+7;

int dp[3005][6005];
int maxA[3005][6005];
int main(){
  int N, T;
  cin >> N >> T;
  vector<pair<int, int>> pr(N);
  vector<int> A(N), B(N);
  REP(i, N){
    cin >> pr[i].first >> pr[i].second;
  }
  sort(pr.begin(), pr.end());
  REP(i, N){
    A[i] = pr[i].first;
    B[i] = pr[i].second;
  }

  REP(i, N+1){
    FOR(j,1,  6005){
      maxA[i][j] = INF;
      dp[i][j] = -1;
    }
  }
  maxA[0][0] = 0;
  dp[0][0] = 0;
  REP(i, N){
    REP(j, T+1+3000){
      if(dp[i][j] == -1) continue;
      if(dp[i+1][j] < dp[i][j]){
        dp[i+1][j] = dp[i][j];
        maxA[i+1][j] = maxA[i][j];
      }
      else if(dp[i+1][j] == dp[i][j]){
        maxA[i+1][j] = max(maxA[i+1][j], maxA[i][j]);
      }
      if(j > T) continue;
      if(dp[i+1][j+A[i]] < dp[i][j] + B[i]){
        dp[i+1][j+A[i]] = dp[i][j] + B[i];
        maxA[i+1][j+A[i]] = max(maxA[i][j], A[i]);
      }
      else if(dp[i+1][j+A[i]] == dp[i][j] + B[i]){
        maxA[i+1][j+A[i]] = max(maxA[i+1][j+A[i]], max(maxA[i][j], A[i]));
      }
    }
  }
  int ans = 0;
  REP(i, 6005){
    if(maxA[N][i] != INF && i-maxA[N][i] < T){
      ans = max(ans, dp[N][i]);
    }
  }
  cout << ans << endl;
  return 0;
}
