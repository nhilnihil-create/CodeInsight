#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int n,m;
  const int max_n = 1e5;
  int a[max_n+1];
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    cin >> a[i];
    a[i] --;
    if(i != 0 && a[i] - a[i-1] == 1){
      cout << 0 << endl;
      return 0;
    }
  }

  unsigned long long dp[max_n+1];
  long long now = 0;
  long long k = 1;
  unsigned long long ans = 1;
  dp[0] = 1;
  for(long long i = 0; i < n; i++){
    if(i == a[now] && now < m){
      // cout << dp[i-1] << endl;
      if(i!=0) ans *= dp[i-1];
      // dp[i] = 1;
      ans %= MOD;
      now ++;
      k = 0;
    }else{
      if(k == 0) dp[i] = 1;
      else if(k == 1) dp[i] = 1;
      else if(k == 2) dp[i] = 2;
      else dp[i] = dp[i-1] + dp[i-2];
      dp[i] %= MOD;
      k++;
    }
  }
  // cout << dp[n-1] << endl;
  ans *= dp[n-1];
  ans %= MOD;

  cout << ans << endl;

  return 0;
}