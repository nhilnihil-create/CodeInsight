#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const long long MOD = 1000000007;


int main() {
  string S;
  cin >> S;
  vector<vector<long long>> dp(110000,vector<long long>(13));
  dp[0][0] = 1;
  REP(i,S.size()){
    int c;
    if (S[i] == '?'){
      c = -1;
    }else{
      c = S[i] - '0';
    }

    REP(j,10){
      if(c!=-1 && c!=j) continue;
      REP(ki,13){
        dp[i+1][(ki*10 + j)%13] += dp[i][ki];
      }
    }
    REP(j,13) dp[i+1][j] %= MOD;
  }

  long long res = dp[S.size()][5];
  cout << res << endl;

}