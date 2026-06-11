#include <bits/stdc++.h>

using namespace std;

short dp[200009][2020];
int main(){
  string s;
  cin >> s;
  memset(dp, 0, sizeof(dp));
  dp[0][s[0]-'0']++;
  for(int i=1;i<s.length();i++){
    dp[i][s[i]-'0']++;
    for(int j=0;j<2019;j++){
      dp[i][(j*10+s[i]-'0')%2019]+=dp[i-1][j];
    }
  }
  int ans=0;
  for(int i=0;i<s.length();i++){
    ans += dp[i][0];
  }
  cout << ans << endl;
}

