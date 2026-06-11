/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t H, N;
  cin >> H >> N;
  vector<int64_t> total_mp(2e4L + 1, kInf);
  total_mp[0] = 0;
  int64_t result = kInf;
  for (int64_t i = 0; i < N; ++i) {
    int64_t damage, mp;
    cin >> damage >> mp;
    for (int64_t prev_damage = 0; prev_damage < H; ++prev_damage) {
      const int64_t next_damage = prev_damage + damage;
      total_mp[next_damage] =
          min(total_mp[next_damage], total_mp[prev_damage] + mp);
      if (next_damage >= H) {
        result = min(result, total_mp[next_damage]);
      }
    }
  }
  cout << result << endl;
  return 0;
}
