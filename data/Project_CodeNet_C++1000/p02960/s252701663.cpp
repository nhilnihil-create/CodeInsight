#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int keta[100005][10];

int main(){
  string s;
  cin >> s;
  reverse(s.begin(),s.end());
  int n = s.size();
  for(int i=0; i<10; ++i){
    keta[0][i] = i;
  }
  for(int i=1; i<=100000; ++i){
    for(int j=0; j<10; ++j){
      keta[i][j] = keta[i-1][j] *10 %13;
    }
  }
  vector<vector<int>> dp(s.size(),vector<int>(13,0));
  for(int i=0; i<n; ++i){
    if(s[i] == '?'){
      if(i == 0) for(int j=0; j<10; ++j){
        dp[0][j] = 1;
      }
      else for(int k=0; k<10; ++k) for(int j=0; j<13; ++j){
        int oj = j -keta[i][k];
        if(oj <0) oj += 13;
        dp[i][j] = dp[i][j] + dp[i-1][oj];
        dp[i][j] %= MOD;
      }
    }else{
      int x = keta[i][s[i] - '0'];
      if(i == 0) dp[0][x] = 1;
      else for(int j=0; j<13; ++j){
        int oj = j-x;
        if(oj <0) oj +=13;
        dp[i][j] = dp[i-1][oj];
      }
    }
  }
  /*
  for(int i=0; i<3; ++i) for(int j=0; j<13; ++j){
    if(j != 12)cout << dp[i][j] << " ";
    else cout << dp[i][j] << endl;
  }
  */
  cout << dp[n-1][5] << endl;
}