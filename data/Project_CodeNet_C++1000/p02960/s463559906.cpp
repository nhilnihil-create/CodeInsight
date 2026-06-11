#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  string s;
  cin >> s;
  int mod = 1e9+7;
  vector<vector<ll>>dp(s.size()+1,vector<ll>(13));
  dp[0][0] = 1;
  rep(i,0,s.size()){
    int c;
    if(s[i] == '?') c = -1;
    else c = s[i]-'0';
    rep(j,0,10){
      if(c != -1 && c != j) continue;
      rep(k,0,13) dp[i+1][(k*10+j)%13] += dp[i][k];
    }
    rep(j,0,13) dp[i+1][j] %= mod;
  }
  cout << dp[s.size()][5] << endl;
}