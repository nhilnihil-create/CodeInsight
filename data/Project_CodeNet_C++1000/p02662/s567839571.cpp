#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=998244353;
int main(){
  ll N,S,dp[3020][3020];
  cin>>N>>S;
  vector<ll> A(N);
  for(ll i=0;i<N;i++){cin>>A.at(i);}
  dp[0][0]=1;
  for(ll i=1;i<=N;i++){
    for(ll j=0;j<=S;j++){
      dp[i][j]=dp[i-1][j]*2%MOD;
      if(j-A.at(i-1)>=0){
        dp[i][j]+=dp[i-1][j-A.at(i-1)]%MOD;
      }
    }
  }
  cout<<dp[N][S]%MOD<<endl;
}