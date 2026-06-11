#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
ll mod=1e9+7;

int main() {
  int n,m;
  cin>>n>>m;
  int s[n];
  int t[m];
  rep(i,n) cin>>s[i];
  rep(i,m) cin>>t[i];
  ll dp[n][m];
  ll sum[n+1][m+1];
  rep(i,n+1) sum[i][0]=0;
  rep(i,m+1) sum[0][i]=0;
  rep(i,n){
    rep(j,m){
      if(s[i]==t[j]) dp[i][j]=(sum[i][j]+1)%mod;
      else dp[i][j]=0;
      sum[i+1][j+1]=(sum[i+1][j]+sum[i][j+1]-sum[i][j]+dp[i][j]+2*mod)%mod;
    }
  }
  cout<<(sum[n][m]+1)%mod<<endl;
}