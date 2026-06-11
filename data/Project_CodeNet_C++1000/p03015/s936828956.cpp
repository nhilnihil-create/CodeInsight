#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1e9+7;

int main(){
  string S; cin >> S;

  // dp[i][0]: 先頭からi桁について，A+B<Sが確定している(a,b)の数
  // dp[i][1]: 先頭からi桁について，A+BとSが一致している(a,b)の数
  vector<vector<int64_t>> dp(1000010, vector<int64_t>(2, 0));
  dp[1][0] = 1;  dp[1][1] = 2;

  for(int i=1; i<S.length(); i++){
    int d = S[i] - '0'; //現在の桁
    for(int da = 0; da<=1; da++){ // aの次の桁が da=0,1
      for(int db = 0; db<=1; db++){ // bの次の桁が db=0,1
        if(da == 1 && db == 1) continue;
        dp[i+1][0] += dp[i][0];

        if(da + db == d){
          dp[i+1][1] += dp[i][1];
        } else if (da + db < d){
          dp[i+1][0] += dp[i][1];
        }

        dp[i+1][0] %= MOD; dp[i+1][1] %= MOD;
      }
    }
  }

  cout << (dp[S.length()][0] + dp[S.length()][1]) % MOD << endl;
}