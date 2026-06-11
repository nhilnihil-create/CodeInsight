#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t N, M;
  cin >> N >> M;
  vector<int64_t> A(N);
  vector<int64_t> B(M);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=0; i<M; i++){
    cin >> B[i];
  }
  
  vector<vector<int64_t>> dp(N+1,vector<int64_t>(M+1,1));
  int64_t MOD = 1e9+7;
  
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      int64_t X = dp[i][j+1] + dp[i+1][j] - dp[i][j];
      if(X < 0){
        X += MOD;
      }
      if(A[i] == B[j]){
        dp[i+1][j+1] = X + dp[i][j];
      }
      else{
        dp[i+1][j+1] = X;
      }
      dp[i+1][j+1] %= MOD;
    }
  }
  /*for(int i=0; i<N+1; i++){
    for(int j=0; j<M+1; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  cout << dp[N][M] << endl;
}