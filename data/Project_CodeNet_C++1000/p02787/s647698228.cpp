#include <iostream>

using namespace std;

int main(){
  int H, N;
  cin >> H >> N;
  int A[N], B[N], cost[N];
  for (int i = 0; i < N; i++){
    cin >> A[i] >> B[i];
  }

  long long dp[N+1][H+1];
  for (int i = 0; i <= N; i++){
    for (int j = 0; j <= H; j++){
      dp[i][j] = 1000000000000000000;
    }
  }

  dp[0][0] = 0;

  for (int i = 0; i < N; i++){
    for (int j = 0; j <= H; j++){
      if(dp[i+1][j] > dp[i][j]){
        dp[i+1][j] = dp[i][j];
      }
      if(dp[i+1][min(j+A[i], H)] > dp[i+1][j] + B[i]){
        dp[i+1][min(j+A[i], H)] = dp[i+1][j] + B[i];
      }
    }
  }
  
  printf("%lld\n", dp[N][H]);
  
}
