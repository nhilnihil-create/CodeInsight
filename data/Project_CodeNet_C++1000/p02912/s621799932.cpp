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

  int64_t N, M;
  cin >> N >> M;
  priority_queue<int64_t> q;
  for (int64_t i = 0; i < N; ++i) {
    int64_t a;
    cin >> a;
    q.push(a);
  }
  for (int64_t i = 0; i < M; ++i) {
    int64_t a = q.top();
    q.pop();
    a /= 2;
    q.push(a);
  }
  int64_t result = 0;
  while (q.size() > 0U) {
    const int64_t a = q.top();
    q.pop();
    result += a;
  }
  cout << result << endl;

  return 0;
}
