#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,m;
  cin >> n >> m;
  ll a[n]={};
  for(int i=0;i<m;i++){
    ll b;
    cin >> b;
    a[b]=1;
  }

  ll dp[100100]={};
  dp[0]=1;
  if(a[1]!=1)dp[1]=1;
  else dp[1]=0;

  for(int i=0;i<n;i++){
    if(a[i+2]!=1)dp[i+2]=(dp[i+1]+dp[i])%mod;
    else dp[i+2]=0;
  }

  cout << dp[n] << endl;

}