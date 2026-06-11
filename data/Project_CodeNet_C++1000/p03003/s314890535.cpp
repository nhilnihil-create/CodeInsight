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
  vector<int> s(n+1,0);
  vector<int> t(m+1,0);
  vector<vector<lint>> dp(n+1,vector<lint>(m+1,1));
  rep1(i,n)cin>>s[i];
  rep1(i,m)cin>>t[i];
  dp[0][0]=1;
  rep1(i,n){
      rep1(j,m){
          dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+MOD;
          dp[i][j]%=MOD;
          if(s[i]==t[j]){
              dp[i][j]+=dp[i-1][j-1];
              dp[i][j]%=MOD;
          }
      }
  }
  cout<<dp[n][m]<<"\n";
  //cout<<"debug"<<endl;
  rep1(i,n*0){
      rep1(j,m){
          cout<<dp[i][j]<<" ";
      }
      cout<<endl;
  }
  return 0;
}