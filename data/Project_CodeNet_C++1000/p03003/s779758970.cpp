#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,M;
  cin>>N>>M;
  vector<int>S(N),T(M);
  for(int i=0;i<N;i++)cin>>S[i];
  for(int i=0;i<M;i++)cin>>T[i];
  vector<vector<int>>dp(N+1,vector<int>(M+1,0));
  dp[0][0]=0;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
      dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
      dp[i][j]=(dp[i][j]-dp[i-1][j-1])%MOD;
      if(dp[i][j]<0)dp[i][j]+=MOD;
      if(S[i-1]==T[j-1])dp[i][j]=(dp[i][j]+dp[i-1][j-1]+1)%MOD;
    }
  }
  cout<<(dp[N][M]+1)%MOD<<endl;
  return 0;
}
