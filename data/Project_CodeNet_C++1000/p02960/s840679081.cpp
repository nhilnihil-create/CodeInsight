#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
  string S;
  cin >> S;

  ll length = S.size();

  vector<vector<ll>> dp(length, vector<ll>(13,0));

  if(S[0] == '?'){
    rep(i, 10) dp[0][i] = 1;
  }
  else{
    int x = S[0] - '0';
    dp[0][x] = 1;
  }

  for(int i = 0; i < length-1; i++){
    for(int j = 0; j < 13; j++){
      if(S[i+1] == '?'){
        rep(k, 10){
          int next_j = (j * 10 + k) % 13;
          dp[i+1][next_j] += dp[i][j];
          dp[i+1][next_j] %= MOD;
        }
      }
      else{
        int x = S[i+1] - '0';
        int next_j = (j * 10 + x) % 13;
        dp[i+1][next_j] += dp[i][j];
        dp[i+1][next_j] %= MOD;
      }
      //cout << dp[i+1][j] <<" ";
    }
    //cout << endl;
  }

  cout << dp[length-1][5] << endl;
}
