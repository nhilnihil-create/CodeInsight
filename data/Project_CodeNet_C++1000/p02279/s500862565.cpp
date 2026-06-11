#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;

typedef struct Node_t
{
  Node_t() {}
  Node_t(int id, int deg, int parent, int depth) : id_(id), deg_(deg),
                                                             parent_(parent), depth_(depth),
                                                             type_(-1) {
    children_ = vector<int>(deg_, -1);
  }
  int id_, deg_, parent_, depth_;
  // 0: root, 1: internal, 2: leaf
  int type_;
  // identifiers of children
  vector<int> children_;
} Node;

void debug_print_node(Node& node)
{
  fprintf(stderr, "DEBUG: id=%d, deg=%d, parent=%d, depth=%d, type=%d\n",
          node.id_, node.deg_, node.parent_, node.depth_, node.type_);
  fprintf(stderr, "DEBUG: children=");
  for (int i = 0; i < node.deg_; ++i) {
    fprintf(stderr, "%d, ", node.children_[i]);
  }
  fprintf(stderr, "\n");
}

void print_node(Node& node)
{
  string type = "root";
  if (node.type_ == 1) { type = "internal node"; }
  else if (node.type_ == 2) { type = "leaf"; }
  fprintf(stdout, "node %d: parent = %d, depth = %d, %s, [",
          node.id_, node.parent_, node.depth_, type.c_str());
  for (int i = 0; i < node.deg_; ++i) {
    if (i) { fprintf(stdout, ", "); }
    fprintf(stdout, "%d", node.children_[i]);
  }
  fprintf(stdout, "]\n");
}

int main()
{
  int n = 0;
  fscanf(stdin, "%d", &n);
  vector<Node> nodes(n);
  for (int i = 0; i < n; ++i) {
    int id, deg;
    fscanf(stdin, "%d %d", &id, &deg);
    vector<int> v(deg, -1);
    Node node(id, deg, -1, -1);
    for (int j = 0; j < deg; ++j) {
      fscanf(stdin, "%d", &node.children_[j]);
    }
    nodes[node.id_] = node;
  }
  // find the root
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < nodes[i].deg_; ++j) {
      nodes[nodes[i].children_[j]].parent_ = nodes[i].id_;
    }
  }
  Node* root = 0;
  for (int i = 0; i < n; ++i) {
    if (nodes[i].parent_ == -1) {
      root = &nodes[i];
      break;
    }
  }
  // this is the root
  root->depth_ = 0;
  root->type_ = 0;
  queue<int> que;
  que.push(root->id_);
  while (!que.empty()) {
    int id = que.front(); que.pop();
    Node& node = nodes[id];
    if (node.type_ != 0 && node.deg_ == 0) {
      // if this is not a root node, neither an internal one,
      // this is a leaf node
      node.type_ = 2;
    }
    else if (node.type_ != 0 && node.deg_ > 0) {
      // not a root node but have children, then this is an internal node
      node.type_ = 1;
    }
    for (int i = 0; i < node.deg_; ++i) {
      // fprintf(stderr, "DEBUG: child of node\n");
      // print_node(nodes[node.children_[i]]);
      nodes[node.children_[i]].depth_ = node.depth_ + 1;
      que.push(node.children_[i]);
    }
  }

  for (int i = 0; i < n; ++i) {
    print_node(nodes[i]);
  }

  return 0;
}