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
  vector<Pair> A(N);
  for (int64_t i = 0; i < N; ++i) {
    int64_t x, l;
    cin >> x >> l;
    A[i].first = x - l;
    A[i].second = x + l;
  }
  auto LessThan = [](const Pair a, const Pair b) -> bool { return a.second < b.second; };
  sort(A.begin(), A.end(), LessThan);
  int64_t result = 0;
  int64_t end = INT64_MIN;
  for (int64_t i = 0; i < N; ++i) {
    if (end <= A[i].first) {
      ++result;
      end = A[i].second;
    }
  }
  cout << result << endl;
  return 0;
}
