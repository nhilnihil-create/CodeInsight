#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 500009
#define MOD 1000000007
#define INF 1000000000

int main(){
  int N,M;
  cin>>N>>M;
  vector<int> S(N),T(M);
  for(int i=0;i<N;i++){
    cin>>S.at(i);
  }
  for(int j=0;j<M;j++){
    cin>>T.at(j);
  }

  vector<vector<ll>> dp(N+1,vector<ll>(M+1,0));
  vector<vector<ll>> sum(N+1,vector<ll>(M+1,0));
  /*
  dp[0][0]=1;
  sum[0][0]=1;
  for(int i=0;i<N;i++){
    sum[i+1][0]=1;
  }
  for(int j=0;j<M;j++){
    sum[0][j+1]=1;
  }
  */
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(S.at(i)==T.at(j)){
        dp[i+1][j+1]=sum[i][j]+1;
        dp[i+1][j+1]%=MOD;
      }
      sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+dp[i+1][j+1]+MOD;
      sum[i+1][j+1]%=MOD;
    }
  }
  cout<<(sum[N][M]+1)%MOD<<endl;
}
