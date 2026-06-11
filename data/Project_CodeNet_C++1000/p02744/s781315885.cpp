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

  int64_t N;
  cin >> N;
  auto Dfs = [&](auto &&Func, string temp, const char end) -> void {
    if (static_cast<int64_t>(temp.length()) == N) {
      cout << temp << endl;
    } else {
      for (char ch = 'a'; ch <= end; ++ch) {
        const char next_end = (ch == end) ? end + 1 : end;
        Func(Func, temp + ch, next_end);
      }
    }
  };

  Dfs(Dfs, "", 'a');
  return 0;
}
