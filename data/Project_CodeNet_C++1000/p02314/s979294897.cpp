//Coin Changing Problem
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1000000

int main(){
  ll n, m;
  cin>>n>>m;
  vector<ll> c;
  for(ll i=0; i<m; i++){
    ll tmp;
    cin>>tmp;
    c.push_back(tmp);
  }
  ll dp[n+1]; //dp[i]:=i????????????????????????????????????????°??????°
  for(ll i=0; i<=n; i++)
    dp[i]=INF;
  dp[0]=0;
  for(ll i=0; i<c.size(); i++){
    for(ll j=0; j<=n; j++){
      if(c[i]<=j)dp[j]=min(dp[j], dp[j-c[i]]+1);
    }
  }
  cout<<dp[n]<<endl;
  return 0;
}