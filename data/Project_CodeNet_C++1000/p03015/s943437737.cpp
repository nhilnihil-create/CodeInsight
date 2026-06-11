#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int main(){
  cin.tie(0);ios::sync_with_stdio(false);
  string s;cin >> s;
  ll n = s.size(),i,dp[n+1][2];dp[0][0] = 1;dp[0][1] = 0;
  for(i=0;i<n;i++){
    if(s[i]=='1'){
      dp[i+1][0] = (dp[i][0]*2)%mod;
      dp[i+1][1] = (dp[i][0]+dp[i][1]*3)%mod;
    }
    else{
      dp[i+1][0] = dp[i][0];
      dp[i+1][1] = (dp[i][1]*3)%mod;
    }
  }
  cout << (dp[n][0]+dp[n][1])%mod << "\n";
}