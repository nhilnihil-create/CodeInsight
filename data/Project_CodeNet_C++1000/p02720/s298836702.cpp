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

  int64_t K;
  cin >> K;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<set<string>> result;
  vector<string> nums = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
  set<string> init = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
  result.emplace_back(init);
  int64_t count = 9;
  if (K <= count) {
    auto itr = init.begin();
    for (int64_t i = 0; i < K - 1; ++i) {
      ++itr;
    }
    cout << *itr << endl;
    return 0;
  }
  while (true) {
    set<string> temp;
    for (const auto &a : result[result.size() - 1]) {
      char head = a.c_str()[0] - '0';
      temp.insert(nums[head] + a);
      if (head > 1) {
        temp.insert(nums[head - 1] + a);
      }
      if (head < 9) {
        temp.insert(nums[head + 1] + a);
      }
      char tail = a.c_str()[a.length() - 1] - '0';
      temp.insert(a + nums[tail]);
      if (tail > 0) {
        temp.insert(a + nums[tail - 1]);
      }
      if (tail < 9) {
        temp.insert(a + nums[tail + 1]);
      }
    }
    result.emplace_back(temp);
    const int64_t c_cnt = static_cast<int64_t>(temp.size());
    if (count + c_cnt < K) {
      count += static_cast<int64_t>(temp.size());
    } else {
      const int64_t n = K - count - 1;
      auto itr = result[result.size() - 1].begin();
      for (int64_t i = 0; i < n; ++i) {
        ++itr;
      }
      cout << *itr << endl;
      break;
    }
  }
  return 0;
}
