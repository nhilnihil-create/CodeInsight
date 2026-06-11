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
#define int long long
using lint=long long;
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n;cin>>n;
  vector<int> a(n+1,0);
  rep1(i,n)cin>>a[i];
  vector<vector<int>> dp(n+1,vector<int>(3,0));
  dp[0][0]=1000;
  rep1(i,n){
      dp[i][0]=max(dp[i-1][0],dp[i-1][1]+dp[i-1][2]*a[i]);
      dp[i][1]=dp[i][0]%a[i];
      dp[i][2]=dp[i][0]/a[i];
  }
  cout<<dp[n][0]<<"\n";
  return 0;
}