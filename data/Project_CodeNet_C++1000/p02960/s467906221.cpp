#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

signed main(){
  string s; cin >> s;
  int n = s.size();
  vector<vector<ll> > dp(n + 1, vector<ll> (13, 0));
  dp[0][0] = 1;
  for(int i = 0; i < n; i++){
    if(s[i] != '?'){
      int num = s[i] - '0';
      for(int j = 0; j < 13; j++){
        int next = (num + 10 * j) % 13;
        (dp[i + 1][next] += dp[i][j]) %= MOD;
      }
    }
    else{
      for(int j = 0; j < 13; j++){
        for(int k = 0; k < 10; k++){
          (dp[i + 1][(10 * j + k) % 13] += dp[i][j]) %= MOD;
        }
      }
    }
  } 
  cout << dp[n][5] << endl;
}