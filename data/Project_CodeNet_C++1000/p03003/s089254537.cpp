#include <bits/stdc++.h>
using namespace std;

int64_t Q=1000000007;

int main(){
  int N,M;
  cin>>N>>M;
  vector<int> p(N);
  vector<int> q(M);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  for(int i=0;i<M;i++){
    cin>>q[i];
  }
  vector<vector<int64_t>> dp(N+1,vector<int64_t>(M+1,1));
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]+Q;
      if(p[i]!=q[j]){
        dp[i+1][j+1]-=dp[i][j];
      }
      dp[i+1][j+1]%=Q;
    }
  }
  cout<<dp[N][M]<<endl;
}