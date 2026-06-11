#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

ll dp[2001][2001];

int main(){
  int n,m;cin>>n>>m;
  vector<int> s(n), t(m);
  rep(i, n)cin>>s[i];
  rep(i, m)cin>>t[i];

  dp[0][0]=1;
  rep1(i, n)dp[i][0]=1;
  rep1(i, m)dp[0][i]=1;

  rep(i, n)rep(j, m){
    if(s[i]==t[j])dp[i+1][j+1] = dp[i+1][j]+dp[i][j+1];
    else dp[i+1][j+1] = dp[i+1][j]+dp[i][j+1]-dp[i][j];
    dp[i+1][j+1]=(dp[i+1][j+1]+MOD)%MOD;
  }

  cout<<dp[n][m]<<endl;

  return 0;
}