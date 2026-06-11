#include <bits/stdc++.h>
using namespace std;
struct Node {
  int parent, left, right;
};
using Nodes = vector<Node>;

int getDepth(const Nodes &nodes, int id) {
  auto node = nodes.at(id);
  if (node.parent != -1) {
    return getDepth(nodes, node.parent) + 1;
  } else {
    return 0;
  }
}
int main() {
  int n, id, k, c;
  deque<int> c_n;
  cin >> n;
  Nodes nodes(n, Node{-1, -1, -1});

  for (size_t i = 0; i < n; i++) {
    cin >> id >> k;
    auto node = nodes.at(id);

    for (size_t j = 0; j < k; j++) {
      cin >> c;
      c_n.push_back(c);
      nodes[c].parent = id;

      if (j == 0) {
        nodes.at(id).left = c;
      } else {
        nodes.at(c_n.at(j - 1)).right = c;
      }
    }
    c_n.clear();
  }

  for (size_t i = 0; i < n; i++) {
    auto no = nodes.at(i);
    string node_type, children = "[";

    if (no.left != -1) {
      node_type = "internal node";
      children += to_string(no.left);

      auto child_sib = nodes[no.left].right;
      while (child_sib != -1) {
        children += ", " + to_string(child_sib);
        child_sib = nodes[child_sib].right;
      }
      children += "]";
    } else {
      node_type = "leaf";
      children += "]";
    }

    if (no.parent == -1) {
      node_type = "root";
    }

    cout << "node " << i << ": parent = " << no.parent
         << ", depth = " << getDepth(nodes, i) << ", " << node_type << ", "
         << children << endl;
  }
}
