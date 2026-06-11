#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

 
int main() {
  string L;
  cin >> L;
  int n = L.size();
  vector<vector<ll>> dp(n+1,vector<ll>(2,0));
  dp[0][0] = 1;
  for(int i=1;i<=n;i++){
    int d = L.at(i-1) - '0';
    if(d == 0){
      dp[i][0] = dp[i-1][0];
      dp[i][1] = (3*dp[i-1][1])%MOD;
    }else{
      dp[i][0] = (2*dp[i-1][0])%MOD;
      dp[i][1] = (3*dp[i-1][1] + dp[i-1][0])%MOD;
    }
  }
  cout << (dp[n][1]+dp[n][0])%MOD << endl;
  return 0;
}

