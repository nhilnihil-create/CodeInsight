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
  string s;cin>>s;
  int n=s.length();
  s+="..";
  vector<vector<int>> dp(n+5,vector<int>(3,0));
  dp[0][0]=1;
  dp[1][1]=1;
  if(s[0]!=s[1])dp[1][0]=2;
  dp[2][0]=dp[1][1]+1;
  if(s[1]!=s[2])dp[2][0]=max(dp[2][0],dp[1][0]+1);
  dp[2][1]=2;

  for(int i=3;i<n;++i){
      dp[i][0]=dp[i-1][1]+1;
      dp[i][1]=dp[i-2][0]+1;
      if(s[i]!=s[i-1])dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
      //if(s.substr(i-1,2)!=s.substr(i-3,2))dp[i][1]=max(dp[i][1],dp[i-2][1]+1);
  }
  /*
  rep(i,n){
      cout<<dp[i][0]<<" ";
  }
  cout<<endl;
  rep(i,n){
      cout<<dp[i][1]<<" ";
  }
  cout<<endl;
  */
  cout<<max(dp[n-1][0],dp[n-1][1])<<"\n";
  return 0;
}