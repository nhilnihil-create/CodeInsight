/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

struct Node {
  int64_t value{0};
  bool visited{false};
  vector<int64_t> nexts;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, Q;
  cin >> N >> Q;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<Node> nodes(N);
  for (int64_t i = 0; i < N - 1; ++i) {
    int64_t a, b;
    cin >> a >> b;
    nodes[a - 1].nexts.emplace_back(b - 1);
    nodes[b - 1].nexts.emplace_back(a - 1);
  }
  for (int64_t i = 0; i < Q; ++i) {
    int64_t p, x;
    cin >> p >> x;
    nodes[p - 1].value += x;
  }

  queue<int64_t> q;
  nodes[0].visited = true;
  q.push(0);
  while (!q.empty()) {
    const int64_t n = q.front();
    q.pop();
    for (const int64_t next : nodes[n].nexts) {
      if (!nodes[next].visited) {
        nodes[next].value += nodes[n].value;
        nodes[next].visited = true;
        q.emplace(next);
      }
    }
  }
  for (int64_t i = 0; i < N; ++i) {
    if (i != 0) {
      cout << " ";
    }
    cout << nodes[i].value;
  }
  cout << endl;
  return 0;
}
