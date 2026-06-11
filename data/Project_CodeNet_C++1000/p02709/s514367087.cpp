#include <bits/stdc++.h>
using namespace std;
int main(){
  
  int N; cin >> N;
  int A[N+1];
  for(int i=0; i<N; i++) cin >> A[i+1];
  
  int64_t dp[2001][2001] = {};
  dp[0][0] = 0;
  bool checked[2001] = {};
  
  for(int i=1; i<=N; i++){
    
    int Max_num = 0;
    int64_t baby;
    
    for(int j=1; j<=N; j++){
      if(!checked[j] && A[j] > Max_num){
        Max_num = A[j];
        baby = j;
      }
    }
    
    checked[baby] = true;
    
    dp[i][0] = (int64_t) dp[i-1][0] + A[baby] * max(baby-i, i-baby);
    for(int j=1; j<i; j++){
      dp[i-j][j] = (int64_t) max(dp[i-j][j-1] + A[baby] * max(baby-(N+1-j), (N+1-j)-baby),
                                 dp[i-j-1][j] + A[baby] * max(baby-(i-j)  , (i-j)-baby  ));
    }
    dp[0][i] = (int64_t) dp[0][i-1] + A[baby] * max(baby-(N+1-i), (N+1-i)-baby);
  }
  
  int64_t ans = 0;
  for(int i=0; i<=N; i++){
    if(dp[i][N-i] > ans) ans = dp[i][N-i];
  }
  cout << ans << endl;
  
}