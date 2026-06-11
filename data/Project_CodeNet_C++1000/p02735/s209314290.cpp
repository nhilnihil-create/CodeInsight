/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t H, W;
  cin >> H >> W;
  vector<vector<bool>> A(H, vector<bool>(W, false));
  for (int64_t r = 0; r < H; ++r) {
    string s;
    cin >> s;
    for (int64_t c = 0; c < W; ++c) {
      const char ch = s.c_str()[c];
      A[r][c] = (ch == '.');
    }
  }
  using DistancePosition = std::pair<int64_t, Pair>;
  vector<vector<int64_t>> distances(H, vector<int64_t>(W, INT64_MAX));
  priority_queue<Pair, vector<DistancePosition>, std::greater<DistancePosition>> q;
  const int64_t initial_distance = (A[H - 1][W - 1]) ? 0 : 1;
  q.push(DistancePosition(initial_distance, Pair(H - 1, W - 1)));
  while (q.size() > 0U) {
    const DistancePosition dp = q.top();
    q.pop();
    const int64_t c_distance = dp.first;
    const Pair c_position = dp.second;
    if (c_position.first == 0 && c_position.second == 0) {
      cout << c_distance << endl;
      break;
    }

    if (c_distance < distances[c_position.first][c_position.second]) {
      distances[c_position.first][c_position.second] = c_distance;

      vector<Pair> nexts;
      if (c_position.first - 1 >= 0) {
        nexts.push_back(Pair(c_position.first - 1, c_position.second));
      }
      if (c_position.second - 1 >= 0) {
        nexts.push_back(Pair(c_position.first, c_position.second - 1));
      }
      for (const auto next : nexts) {
        int64_t next_distance = c_distance;
        if (A[next.first][next.second] == false && A[c_position.first][c_position.second] == true) {
          ++next_distance;
        }
        q.push(DistancePosition(next_distance, next));
      }
    }
  }

  return 0;
}
