#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 998244353
#define INF 1000000000000000LL

using namespace std;

#define MAXNS 3001
ll dp[MAXNS][MAXNS];

int main(){
  int n,s;cin>>n>>s;
  vector<int>a(n);
  rep(i, n)cin>>a[i];

  dp[0][0]=1;
  rep(i, n)rep(j, s+1){
    ll cn = a[i];
    dp[i+1][j] += dp[i][j]*2;
    dp[i+1][j]%=MOD;
    if(j+cn<=s){
      dp[i+1][j+cn] += dp[i][j];
      dp[i+1][j+cn] %= MOD;
    }
  }

  cout<<dp[n][s]<<endl;

  return 0;

rep(i, n+1){
  rep(j, s+1)cout<<dp[i][j]<<' ';cout<<endl;
}

  return 0;
}