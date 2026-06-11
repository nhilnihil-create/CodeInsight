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
  cin >> N;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<int64_t> A(N + 1);
  for (int64_t i = 0; i <= N; ++i) {
    cin >> A[i];
  }
  vector<Pair> range(N + 1);
  range[N].first = A[N];
  range[N].second = A[N];
  for (int64_t depth = N - 1; depth >= 0; --depth) {
    range[depth].first = A[depth] + range[depth + 1].first / 2 + (range[depth + 1].first % 2);
    range[depth].second = A[depth] + range[depth + 1].second;
  }
  if (range[0].first > 1 || range[0].second < 1) {
    cout << -1 << endl;
    return 0;
  }

  vector<int64_t> number_of_nodes(N + 1, 0);
  number_of_nodes[0] = 1;
  int64_t result = number_of_nodes[0];
  for (int64_t depth = 1; depth <= N; ++depth) {
    number_of_nodes[depth] = min(range[depth].second, (number_of_nodes[depth - 1] - A[depth - 1]) * 2);
    result += number_of_nodes[depth];
  }
  cout << result << endl;
  return 0;
}
