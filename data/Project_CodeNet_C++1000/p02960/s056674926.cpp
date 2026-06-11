#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  string S;
  cin >> S;

  vector<vector<ll>> dp(S.size(), vector<ll>(13, 0));

  // initialize
  if(S[0] == '?'){
    for(int i = 0; i <= 9; i++){
      dp[0][i] = 1;
    }
  } else {
    int tmp = S[0] - '0';
    dp[0][tmp] = 1;
  }

  for(int i = 0; i < S.size()-1; i++){
    if(S[i+1] != '?'){
      int tmp = S[i+1] - '0';
      for(int j = 0; j <= 12; j++){
        dp[i+1][(10*j+tmp)%13] += dp[i][j];
        dp[i+1][(10*j+tmp)%13] %= MOD;
      }
    } else { 
      for(int k = 0; k <= 9; k++){
        for(int j = 0; j <= 12; j++){
          dp[i+1][(10*j+k)%13] += dp[i][j];
          dp[i+1][(10*j+k)%13] %= MOD;
        }
      }
    }
  }

  cout << dp[S.size()-1][5] << endl;

}
