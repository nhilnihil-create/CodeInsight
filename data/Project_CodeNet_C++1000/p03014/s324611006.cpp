#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
ll MEMO[2001][2001][4];
// 0: Left, 1: Up, 2: Right, 3:Down
int main() {
  ll H, W;
  cin >> H >> W;
  vector<string> map(H);
  for (int i = 0; i < H; i++) {
    cin >> map[i];
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (map[i][j] == '#') continue;
      MEMO[i][j][0] = (j == 0) ? 1 : (MEMO[i][j - 1][0] + 1);
      MEMO[i][j][1] = (i == 0) ? 1 : (MEMO[i - 1][j][1] + 1);
    }
  }
  for (int i = H - 1; i >= 0; i--) {
    for (int j = W - 1; j >= 0; j--) {
      if (map[i][j] == '#') continue;
      MEMO[i][j][2] = (j == W - 1) ? 1 : (MEMO[i][j + 1][2] + 1);
      MEMO[i][j][3] = (i == H - 1) ? 1 : (MEMO[i + 1][j][3] + 1);
    }
  }
  ll ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (map[i][j] == '.')
        ans = max(ans, MEMO[i][j][0] + MEMO[i][j][1] + MEMO[i][j][2] +
                           MEMO[i][j][3] - 3);
    }
  }
  cout << ans << endl;
  return 0;
}