#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N,M;
  cin >>N>>M;
  ll a=pow(10,9)+7;
  vector<ll> dp(N+1,0);
  dp[1]=1;
  for(int i=0;i<=M;i++){
    int a;
    cin >>a;
    dp[a]=-1;
  }
  dp[0]=1;
  for(int i=2;i<=N;i++){
    if(dp[i]==-1){
      continue;
    }
    if(dp[i-1]!=-1){
      dp[i]+=dp[i-1];
    }
    if(dp[i-2]!=-1){
      dp[i]+=dp[i-2];
    }
    if(dp[i]>=a){
      dp[i]%=a;
    }
  }
  cout << dp[N] <<endl;
}
