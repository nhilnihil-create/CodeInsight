/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

constexpr int64_t kInf = INT64_MAX / 2L;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t H, N;
  cin >> H >> N;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<int64_t> total_mp(H + 1, kInf);
  total_mp[0] = 0;
  for (int64_t i = 0; i < N; ++i) {
    int64_t damage, mp;
    cin >> damage >> mp;
    for (int64_t d = 0; d < H; ++d) {
      const int64_t next_daname = min(H, d + damage);
      total_mp[next_daname] = min(total_mp[next_daname], total_mp[d] + mp);
    }
  }
  cout << total_mp[H] << endl;
  return 0;
}
