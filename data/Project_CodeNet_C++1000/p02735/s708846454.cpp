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

int main(){
  int h,w;cin>>h>>w;
  vector<string> s(h);
  rep(i, h)cin>>s[i];

  vector<vector<int>> dp(h, vector<int>(w) );
  rep(i, h)rep(j, w)dp[i][j]=1000000;
  dp[0][0]=0;
  rep(i, h)rep(j, w){
    if(i<h-1)dp[i+1][j] = min(dp[i+1][j], dp[i][j]+(s[i][j]!=s[i+1][j] ? 1 : 0) );
    if(j<w-1)dp[i][j+1] = min(dp[i][j+1], dp[i][j]+(s[i][j]!=s[i][j+1] ? 1 : 0) );
  }
  int result=dp[h-1][w-1];
  if(s[0][0]=='#')result++;
  if(s[h-1][w-1]=='#')result++;
  cout<<result/2<<endl;

  return 0;

  rep(i, h){
    rep(j,w)cout<<dp[i][j];cout<<endl;
  }

  return 0;
}