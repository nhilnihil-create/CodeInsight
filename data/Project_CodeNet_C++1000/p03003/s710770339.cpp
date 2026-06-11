#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=1000000007;
int main(){
int N,M;
  cin>>N>>M;
  vector<int>S(N);
  for(int i=0;i<N;i++)
    cin>>S.at(i);
  vector<int>T(M);
  for(int i=0;i<M;i++)
    cin>>T.at(i);
  vector<vector<int>>dp(1+N,vector<int>(1+M,1));
  for(int i=1;i<=N;i++){
  for(int j=1;j<=M;j++){
  if(S.at(i-1)==T.at(j-1))
    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    else
      dp[i][j]=(mod+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%mod;
  
  }
  }cout<<dp[N][M]<<endl;
   return 0;
}