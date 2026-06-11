#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
using lint=long long;
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n;cin>>n;
  string s;cin>>s;
  vector<vector<int>> dp(n+1,vector<int>(n+1,0));
  int res=0;
  rep1(i,n){
      rep1(j,n){
          if(s[i-1]==s[j-1])dp[i][j]=dp[i-1][j-1]+1;
          dp[i][j]=min(dp[i][j],abs(i-j));
          res=max(res,dp[i][j]);
      }
  }
  cout<<res<<"\n";
  return 0;
}