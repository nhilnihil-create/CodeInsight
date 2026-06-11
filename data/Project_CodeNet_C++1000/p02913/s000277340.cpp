#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
  int n; cin >> n;
  string s; cin >> s;

  int dp[n][n];

  for(int i = n - 1; i >= 0; i--){
    for(int j = n - 1; j >= 0; j--){
      if(s[j] != s[i]){
        dp[i][j] = 0;
        continue;
      }
      if(i + 1 >= n || j + 1 >= n) dp[i][j] = 1;
      else dp[i][j] = dp[i + 1][j + 1] + 1;
    }
  }

  int ans = 0;
  rep(i, n){
    rep(j, n){
      ans = max(ans, min(abs(i - j), dp[i][j]));
      //cout << dp[i][j] << " ";
    }
    //cout << endl;
  }
  cout << ans << endl;
  return 0;
}
