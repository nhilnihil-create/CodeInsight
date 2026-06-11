#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct Node {
  int number;
  int parent = -1;
  int depth;
  string type;
  std::vector<int> children;
};

std::vector<Node> nodes;

void check_parent() {
  for (Node node : nodes) {
    for (int child : node.children) {
      nodes[child].parent = node.number;
    }
  }
}

void check_depth() {
  for (Node node : nodes) {
    int parent = node.parent;
    int depth = 0;
    while (parent != -1) {
      parent = nodes[parent].parent;
      depth++;
    }
    nodes[node.number].depth = depth;
  }
}

void check_type() {
  for (Node node : nodes) {
    if (node.parent == -1) {
      nodes[node.number].type = "root";
    } else if (node.children.empty()) {
      nodes[node.number].type = "leaf";
    } else {
      nodes[node.number].type = "internal node";
    }
  }
}

void sort_node() {
  sort(nodes.begin(), nodes.end(),
       [](const Node &x, const Node &y) { return x.number < y.number; });
}

int main() {
  // input
  int n;
  cin >> n;

  rep(i, n) {
    Node node;
    cin >> node.number;

    int d;
    cin >> d;
    rep(j, d) {
      int child;
      cin >> child;
      node.children.push_back(child);
    }
    nodes.push_back(node);
  }

  // process
  sort_node();
  check_parent();
  check_depth();
  check_type();

  // output
  for (Node node : nodes) {
    std::cout << "node " << node.number << ": parent = " << node.parent
              << ", depth = " << node.depth << ", " << node.type << ", ";
    std::cout << "[";
    for (int i = 0; i < node.children.size(); i++) {
      if (i)
        std::cout << ", ";
      std::cout << node.children[i];
    }
    std::cout << "]" << '\n';
  }

  return 0;
}

