/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

char buff[100];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  string S;
  cin >> N >> S;
  int64_t result = 0;
  for (int64_t i = 0; i < 1000; ++i) {
    snprintf(buff, sizeof(buff), "%03ld", i);
    string temp(buff);
    int64_t j = 0;
    bool is_okay = true;
    for (int64_t t = 0; t < 3; ++t) {
      while (j < N && temp[t] != S[j]) {
        ++j;
      }
      if (j >= N) {
        is_okay = false;
        break;
      }
      ++j;
    }
    if (is_okay) {
      ++result;
    }
  }
  cout << result << endl;
  return 0;
}
