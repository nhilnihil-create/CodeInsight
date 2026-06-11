#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

struct NODE {
  int id;
  int parent;
  int depth;
  vector<int> child;
  
  NODE() : id(), parent(-1), depth(0), child(0, 0) {}
};

static vector<NODE> TREE(100000);

static void inputNode(NODE& node, int id, int k) {
  node.id = id;

  int c;
  for (int i = 0; i < k; i++) {
    cin >> c;
    node.child.push_back(c);
  }
}

static const string ROOT = "root";
static const string INTERNAL_NODE = "internal node";
static const string LEAF = "leaf";

static const string& getNodeType(const NODE& node) {
  if (node.parent == -1) {
    return ROOT;
  } else if (node.child.size() != 0) {
    return INTERNAL_NODE;
  } else {
    return LEAF;
  }
}

static void setDepth(vector<NODE>& tree, NODE& node) {
  for (int i : node.child) {
    tree[i].depth = node.depth + 1;
    setDepth(tree, tree[i]);
  }
}

static void setup(vector<NODE>& tree, int num) {
  for (int i = 0; i < num; i++) {
    const NODE& node = tree[i];
    for (int j : node.child) {
      tree[j].parent = node.id;
      tree[j].depth = node.depth + 1;
      setDepth(tree, tree[j]);
    }
  }
}

static void printTree(const vector<NODE>& tree, int num) {
  int node, parent = -1, depth = 0;

  for (int i = 0; i < num; i++) {
    const string type = getNodeType(tree[i]);
    printf("node %d: parent = %d, depth = %d, %s, [", i, tree[i].parent, tree[i].depth, type.c_str());
    for (int j  = 0; j < tree[i].child.size(); j++) {
      if (j != 0) {
        printf(", "); 
      }
      printf("%d", tree[i].child[j]);
    }
    printf("]\n");
  }
}

int main() {
  int n;
  cin >> n;

  int id, k;
  for (int i = 0; i < n; i++) {
    cin >> id >> k;
    inputNode(TREE[id], id, k);
  }
  
  setup(TREE, n);
  printTree(TREE, n);

  return 0;
}

