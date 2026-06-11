#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)
#define MOD 1000000007

int main() {
  int n,m;
  cin >> n >> m;
  ll dp[n+10];
  rep(i,n+10) dp[i] = 0;
  dp[0] = 1;
  bool a[n+1];
  rep(i,n+1) a[i] = 1;
  int ai;
  rep(i,m) {
    cin >> ai;
    a[ai] = 0;
  }
  rep(i,n) {
    if (a[i]) {
      dp[i+1] = (dp[i]+dp[i+1])%MOD;
      dp[i+2] = (dp[i]+dp[i+2])%MOD;
    }
  }
  cout << dp[n] << endl;
  return 0;
}