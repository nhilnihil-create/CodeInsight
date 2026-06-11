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
ll MEMO[2001][2001];

int main() {
  ll H, W;
  cin >> H >> W;
  vector<string> map(H);
  for (int i = 0; i < H; i++) {
    cin >> map[i];
  }
  for (int i = 0; i < H; i++) {
    ll left_serial_cnt = 0, right_serial_cnt = 0;
    for (int j = 0; j < W; j++) {
      MEMO[i][j] += left_serial_cnt++;
      if (map[i][j] == '#') left_serial_cnt = 0;
      MEMO[i][W - j - 1] += right_serial_cnt++;
      if (map[i][W - j - 1] == '#') right_serial_cnt = 0;
    }
  }
  for (int j = 0; j < W; j++) {
    ll up_serial_cnt = 0, down_serial_cnt = 0;
    for (int i = 0; i < H; i++) {
      MEMO[i][j] += up_serial_cnt++;
      if (map[i][j] == '#') up_serial_cnt = 0;
      MEMO[H - i - 1][j] += down_serial_cnt++;
      if (map[H - i - 1][j] == '#') down_serial_cnt = 0;
    }
  }
  ll ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (map[i][j] == '.') ans = max(ans, MEMO[i][j]);
    }
  }
  cout << ans + 1 << endl;
  return 0;
}