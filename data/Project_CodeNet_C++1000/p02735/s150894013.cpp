#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> s(H, vector<char>(W, '#'));
  REP(y, H) {
    REP(x, W) {
      cin >> s[y][x];
    }
  }

  vector<vector<long long>> dp(H, vector<long long>(W, INF));
  if (s[0][0] == '.') dp[0][0] = 0;
  else dp[0][0] = 1;
  REP(y, H) {
    REP(x, W) {
      if (y + 1 < H) {
        if (s[y][x] == '.' && s[y + 1][x] == '#') chmin(dp[y + 1][x], dp[y][x] + 1);
        else chmin(dp[y + 1][x], dp[y][x]);
      }
      if (x + 1 < W) {
        if (s[y][x] == '.' && s[y][x + 1] == '#') chmin(dp[y][x + 1], dp[y][x] + 1);
        else chmin(dp[y][x + 1], dp[y][x]);
      }
    }
  }
  cout << dp[H - 1][W - 1] << endl;
  return 0;
}