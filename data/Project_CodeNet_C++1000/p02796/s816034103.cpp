/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

struct Range {
  int64_t from{-1};
  int64_t until{-1};
};

bool LessThan(const Range &a, const Range &b) {
  return a.until < b.until;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  cin >> N;
  vector<Range> A(N);
  for (int64_t i = 0; i < N; ++i) {
    int64_t x, l;
    cin >> x >> l;
    A[i].from = x - l;
    A[i].until = x + l;
  }
  sort(A.begin(), A.end(), LessThan);
  int64_t count = 0;
  int64_t until = INT64_MIN;
  for (int64_t i = 0; i < N; ++i) {
    if (until <= A[i].from) {
      ++count;
      until = A[i].until;
    }
  }
  cout << count << endl;

  return 0;
}
