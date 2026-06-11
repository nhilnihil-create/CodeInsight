#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = n; i >= 0; --i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;
 
const int MOD = 1e9 + 7;
 
string S;
ll dp[100001][13];

 
int main() {  
  cin >> S;
  int n = S.size();
  int mul = 1;


  dp[0][0] = 1;

  REP(i,n) {
    char c = S[n-i-1];

    if ( c == '?') {
      REP(mod, 13) {
        REP(d, 10) {
          int j = (d * mul + mod) % 13;
          dp[i+1][j] += dp[i][mod];
          dp[i+1][j] %= MOD;
        }
      }

    } else {
      int num = c - '0';

      REP(mod,13) {
        // cout << mod << endl;
        int j = (num * mul + mod) % 13;
        dp[i+1][j] += dp[i][mod];
        dp[i+1][j] %= MOD;
      }
    }
    mul *= 10;
    mul %= 13;
  }

  cout << dp[n][5] % MOD << endl;

}