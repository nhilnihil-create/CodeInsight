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
  int n,t;cin>>n>>t;
  vector<P> input(n);
  rep(i,n)cin>>input[i].first>>input[i].second;
  sort(input.begin(),input.end());
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n){
      a[i]=input[i].first;b[i]=input[i].second;
  }
  int mx=b[n-1];
  vector<vector<int>> dp(n,vector<int>(t+5,0));
  for(int i=a[0];i<t;++i)dp[0][i]=b[0];
  rep1(i,n-1){
      for(int j=t-1;j>0;--j){
          dp[i][j]=dp[i-1][j];
          if(j<a[i])continue;
          dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]+b[i]);
      }
  }
  int res=0;
  for(int i=n-1;i>0;--i){
      mx=max(mx,b[i]);
      res=max(res,dp[i-1][t-1]+mx);
  }
  cout<<res<<"\n";
  return 0;
}