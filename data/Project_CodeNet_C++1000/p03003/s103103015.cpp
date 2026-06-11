#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,m;
  cin >> n>> m;

  ll s[n],t[m];
  for(int i=0;i<n;i++)cin >> s[i] ;
  for(int i=0;i<m;i++)cin >> t[i];

  ll dp[n+1][m+1];//i番目とj番目までの部分列で、かつi番目とj番目を使用している組 
  memset(dp,0,sizeof(dp));
  ll l[n+1][m+1];
  memset(l,0,sizeof(l));
  

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i]==t[j])dp[i+1][j+1]=l[i][j]+1;
      dp[i+1][j+1]%=mod;
      l[i+1][j+1]+=l[i+1][j];
      l[i+1][j+1]%=mod;
      l[i+1][j+1]+=l[i][j+1];
      l[i+1][j+1]%=mod;
      l[i+1][j+1]-=l[i][j];
      l[i+1][j+1]+=mod;
      l[i+1][j+1]%=mod;
      l[i+1][j+1]+=dp[i+1][j+1];
      l[i+1][j+1]%=mod;
    }
  }

  cout << (l[n][m]+1)%mod << endl;


}