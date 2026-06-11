#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

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
  string s;cin>>s;
  int n=s.size();
  vector<vector<int>> dp(2,vector<int>(n,0));
  dp[0][0]=1;dp[1][0]=2;
  rep1(i,n-1){
    if(s[i]=='0'){
      dp[0][i]=dp[0][i-1]*3;
      dp[1][i]=dp[1][i-1];
    }
    else{
      dp[0][i]=dp[0][i-1]*3+dp[1][i-1];
      dp[1][i]=dp[1][i-1]*2;
    }
    dp[0][i]%=MOD;
    dp[1][i]%=MOD;
  }
  cout<<(dp[0][n-1]+dp[1][n-1])%MOD<<"\n";
  return 0;
}
