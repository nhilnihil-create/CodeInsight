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
  string l;cin>>l;
  int n=l.length();
  vector<vector<int>> dp(2,vector<int>(n+5,0));
  dp[0][0]=2;
  dp[1][0]=1;
  rep1(i,n-1){
    if(l[i]=='1'){
      dp[0][i]=dp[0][i-1]*2;
      dp[0][i]%=MOD;
      dp[1][i]=dp[1][i-1]*3+dp[0][i-1];
      dp[1][i]%=MOD;
    }
    else{
      dp[0][i]=dp[0][i-1];
      dp[1][i]=dp[1][i-1]*3;
      dp[1][i]%=MOD;
    }
  }
  cout<<(dp[0][n-1]+dp[1][n-1])%MOD<<"\n";
  return 0;
}
