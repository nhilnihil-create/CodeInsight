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
  int h,n;cin>>h>>n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n)cin>>a[i]>>b[i];
  vector<int> dp(h+5,inf);
  dp[0]=0;
  rep(i,n){
      rep(j,h){
          int buf=min(h,j+a[i]);
          dp[buf]=min(dp[buf],dp[j]+b[i]);
      }
  }
  cout<<dp[h]<<"\n";
  return 0;
}