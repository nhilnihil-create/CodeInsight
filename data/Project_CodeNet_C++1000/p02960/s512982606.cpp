#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// const int INF = 2100100100;
const int MOD = 1e9 + 7;

int dp[110000][13];


int main() {
  string S; cin >> S;
  int len = S.size();
  reverse(S.begin(), S.end());

  if (S[0] == '?') {
    REP(change, 10) {
      dp[0][change] = 1;
    }
  }
  else {
    dp[0][S[0] - '0'] = 1;
  }

  int base = 1;
  for(int i = 1; i < len; i++) {
    base *= 10;
    base %= 13;
    

    if (S[i] == '?') {
      REP(change, 10) {
        REP(old_r, 13) {
          int new_r = (base * change + old_r) % 13;
          // 貰うDP
          dp[i][new_r] += dp[i - 1][old_r];
          dp[i][new_r] %= MOD;
        }
      }
    }
    else {
      int change = S[i] - '0';
      REP(old_r, 13) {
        int new_r = (base * change + old_r) % 13;
        dp[i][new_r] += dp[i - 1][old_r];
        dp[i][new_r] %= MOD;
      }
    }
  }
  // REP(i, len) cout << dp[i][5] << endl;
  cout << dp[len - 1][5] << endl;

  return 0;
}