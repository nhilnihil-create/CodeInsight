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

  int64_t N;
  string S;
  cin >> N >> S;
  enum RGBtype : int64_t { kR = 0L, kG, kB, kNumber };
  vector<int64_t> A(N);
  vector<int64_t> counts(3, 0);
  for (int64_t i = 0; i < N; ++i) {
    const char ch = S.c_str()[i];
    if (ch == 'R') {
      A[i] = kR;
      ++counts[kR];
    } else if (ch == 'G') {
      A[i] = kG;
      ++counts[kG];
    } else if (ch == 'B') {
      A[i] = kB;
      ++counts[kB];
    }
  }

  vector<int64_t> rgb_index = {0, 1, 2};
  int64_t result = 1;
  for (const int64_t count : counts) {
    result *= count;
  }

  for (int64_t i = 0; i < N; ++i) {
    for (int64_t j = i + 1; j < N; ++j) {
      const int64_t k = j * 2LL - i;
      if (k < N && A[i] != A[j] && A[j] != A[k] && A[i] != A[k]) {
        --result;
      }
    }
  }

  cout << result << endl;

  return 0;
}
