#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
const long long INF=1000000007;
typedef long long ll;

int main() {
  ll N,M;
  cin>>N>>M;
  ll a[M];
  vector<bool> j(N,true);
  rep(i,M){
    cin>>a[i];
    j[a[i]]=false;
  }
  ll dp[N+1];
  dp[0]=0;
  if(j[1]==true&&j[2]==true){
    dp[1]=1;
    dp[2]=2;
  }
  else if(j[1]==false&&j[2]==true){
    dp[1]=0;
    dp[2]=1;
  }
  else if(j[1]==true&&j[2]==false){
    dp[1]=1;
    dp[2]=0;
  }
  else{
    dp[1]=0;
    dp[2]=0;
  }
  
  for(ll i=3;i<=N;i++){
    if(j[i-1]==true&&j[i-2]==true){
      dp[i]=dp[i-1]+dp[i-2];
      dp[i]%=INF;
    }
    else if(j[i-1]==false&&j[i-2]==true){
      dp[i]=dp[i-2];
      dp[i]%=INF;
    }
    else if(j[i-1]==true&&j[i-2]==false){
      dp[i]=dp[i-1];
      dp[i]%=INF;
    }
    else{
      dp[i]=0;
    }
  }
  cout<<dp[N]<<endl;
}