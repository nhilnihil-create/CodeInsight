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

  int64_t X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  enum Color : int64_t { kRed = 0, kGreen, kTrans };
  vector<pair<int64_t, Color>> apples;
  for (int64_t i = 0; i < A; ++i) {
    int64_t z;
    cin >> z;
    apples.emplace_back(z, kRed);
  }
  for (int64_t i = 0; i < B; ++i) {
    int64_t z;
    cin >> z;
    apples.emplace_back(z, kGreen);
  }
  for (int64_t i = 0; i < C; ++i) {
    int64_t z;
    cin >> z;
    apples.emplace_back(z, kTrans);
  }
  sort(apples.begin(), apples.end());
  reverse(apples.begin(), apples.end());

  int64_t result = 0;
  int64_t count_red = 0;
  int64_t count_green = 0;
  int64_t count_trans = 0;
  for (const auto &apple : apples) {
    const int64_t value = apple.first;
    const Color color = apple.second;
    if (color == kRed) {
      if (count_red < X) {
        result += value;
        ++count_red;
      }
    } else if (color == kGreen) {
      if (count_green < Y) {
        result += value;
        ++count_green;
      }
    } else {
      result += value;
      ++count_trans;
    }
    if (count_red + count_green + count_trans == X + Y) {
      break;
    }
  }
  cout << result << endl;
  return 0;
}
