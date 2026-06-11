#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int main(){
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<ll>> dp(n+1, vector<ll>(2,0));
  dp[0][1] = 1;
  for(int i=0; i<n; ++i){
    if(s[i] == '1'){
      dp[i+1][0] = (dp[i][0] *3 + dp[i][1]) %MOD;
      dp[i+1][1] = dp[i][1] *2 %MOD;
    }else{
      dp[i+1][0] = dp[i][0] *3 %MOD;
      dp[i+1][1] = dp[i][1] %MOD;
    }
  }
  cout << (dp[n][0] +dp[n][1]) %MOD << endl;
}