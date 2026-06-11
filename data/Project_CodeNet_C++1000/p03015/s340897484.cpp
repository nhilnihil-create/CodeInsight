#include<bits/stdc++.h>
using namespace std;
int main(){
  string l;
  cin >> l;
  vector<vector<long> >dp(l.length(),vector<long>(2,0)); // 0:　まだLを守ってる　1::Lを破る

  dp[0][0] = 2;
  dp[0][1] = 1;

  long const MOD = 1e9+7;

  for(int i=1;i<l.length();i++){
    if(l[i] == '0'){
      dp[i][1] = dp[i-1][1] * 3;
      dp[i][1] %= MOD;
      dp[i][0] = dp[i-1][0];
    }else{
      dp[i][0] = 2 * dp[i-1][0];
      dp[i][0] %= MOD;

      dp[i][1] = dp[i-1][1]*3 + dp[i-1][0];
      dp[i][1] %= MOD;
    }
  }
  cout << (dp[l.length()-1][0] + dp[l.length()-1][1])%MOD<<endl;
  
  
}
