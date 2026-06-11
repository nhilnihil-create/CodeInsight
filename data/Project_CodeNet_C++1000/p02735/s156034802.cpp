#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  vector<string> field(h);
  for (int i = 0; i < h; i++) cin >> field[i];
  vector<vector<int>> dp(h, vector<int>(w, -1));

  dp[h-1][w-1] = ((field[h-1][w-1]=='.') ? 0 : 1);
  for (int y = h-2; y >= 0; y--) {
    dp[y][w-1] = (((field[y][w-1] == '#') && (field[y+1][w-1] == '.')) ? dp[y+1][w-1] + 1 : dp[y+1][w-1]);
  }

  for (int x = w-2; x >= 0; x--) {
    for (int y = h-1; y >= 0; y--) {
      if (y == h-1) {
        dp[y][x] = dp[y][x+1] + (((field[y][x] == '#') && (field[y][x+1] == '.')) ? 1 : 0);
      }
      else {
        dp[y][x] = min(dp[y][x+1] + (((field[y][x] == '#') && (field[y][x+1] == '.')) ? 1 : 0), dp[y+1][x] + (((field[y][x] == '#') && (field[y+1][x] == '.') ? 1 : 0)));
      }
    }
  }

  cout << dp[0][0] << endl;
}
