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
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000000000000007;
const int MOD=1000000007;
signed main(){
  int n,k;cin>>n>>k;
  vector<int> a(n+1,0);
  rep1(i,n){
      cin>>a[i];
  }
  vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,inf)));
  //dp[0][0][1]=a[1];
  dp[0][0][0]=0;
  //dp[0][1][0]=0;
  //cout<<"OK"<<endl;
  rep1(i,n){
      rep(j,n+1){
          rep(l,n+1){
              dp[i][j][i]=min(dp[i][j][i],dp[i-1][j][l]+max(a[i]-a[l],(int)0));
              if(j>0)dp[i][j][l]=min(dp[i][j][l],dp[i-1][j-1][l]);
          }
      }
  }
  int res=inf;
  rep(i,n+1){
      res=min(res,dp[n][k][i]);
  }
  cout<<res<<"\n";
  return 0;
}