/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

struct Node {
  int64_t parent{-1};
  // vector<int64_t> children;
  vector<int64_t> neighbours;
  int64_t offset{0};
  int64_t value{-1};
};

void SetParent(const int64_t cnode, vector<Node> &nodes) {
  for (const int64_t neighbour : nodes[cnode].neighbours) {
    if (nodes[neighbour].parent < 1) {
      nodes[neighbour].parent = cnode;
      SetParent(neighbour, nodes);
    }
  }
}

void UpdateValues(const int64_t cnode, const int64_t carried, vector<Node> &nodes) {
  nodes[cnode].value = nodes[cnode].offset + carried;
  for (const int64_t neighbour : nodes[cnode].neighbours) {
    if (nodes[neighbour].value < 0) {
      UpdateValues(neighbour, nodes[cnode].value, nodes);
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  constexpr int64_t kRoot = 1;
  int64_t N, Q;
  cin >> N >> Q;
  vector<Node> nodes(N + 1);
  nodes[kRoot].parent = kRoot;
  for (int64_t i = 0; i < N - 1; ++i) {
    int64_t a, b;
    cin >> a >> b;
    nodes[a].neighbours.push_back(b);
    nodes[b].neighbours.push_back(a);
  }

  SetParent(kRoot, nodes);

  for (int64_t i = 0; i < Q; ++i) {
    int64_t p, x;
    cin >> p >> x;
    nodes[p].offset += x;
  }

  UpdateValues(kRoot, 0, nodes);
  for (int64_t i = 1; i <= N; ++i) {
    if (i != 1) {
      cout << " ";
    }
    const int64_t result = nodes[i].value;
    cout << result;
  }
  cout << endl;

  return 0;
}
