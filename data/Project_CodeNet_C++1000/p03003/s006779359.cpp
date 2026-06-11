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
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n,m;cin>>n>>m;
  vector<int> s(n+1,0);
  vector<int> t(m+1,0);
  rep1(i,n)cin>>s[i];
  rep1(i,m)cin>>t[i];
  vector<vector<int>> dp(n+5,vector<int>(m+5,0));
  vector<vector<int>> sm(n+5,vector<int>(m+5,0));
  rep1(i,n){
      rep1(j,m){
          if(s[i]==t[j]){
              dp[i][j]+=sm[i-1][j-1]+MOD+1;
              dp[i][j]%=MOD;
          }
              sm[i][j]+=sm[i-1][j]+sm[i][j-1]-sm[i-1][j-1]+dp[i][j]+MOD;
              sm[i][j]%=MOD;
      }
  }
  int res=1;
  //cout<<"debug"<<"\n";
  rep1(i,n){
      rep1(j,m){
          res+=dp[i][j];
          res%=MOD;
          //cout<<dp[i][j]<<" ";
      }
      //cout<<endl;
  }
  cout<<res<<"\n";
  return 0;
}