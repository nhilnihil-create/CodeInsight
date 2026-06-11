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
  int n,m;cin>>n>>m;
  vector<int> a(m);
  vector<int> c(m,0);
  rep(i,m){
      int b;cin>>a[i]>>b;
      rep(j,b){
          int buf;cin>>buf;
          --buf;
          c[i]+=(1<<buf);
      }
  }
  vector<vector<lint>> dp(m,vector<lint>((1<<n),inf));
  dp[0][0]=0;
  dp[0][c[0]]=a[0];
  rep1(i,m-1){
      for(int j=0;j<(1<<n);++j){
          dp[i][j]=min(dp[i][j],dp[i-1][j]);
          dp[i][j|c[i]]=min(dp[i-1][j]+a[i],dp[i][j|c[i]]);
      }
  }
  int res=dp[m-1][(1<<n)-1];
  if(res==inf)res=-1;
  cout<<res<<"\n";
  return 0;
}