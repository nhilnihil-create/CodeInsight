#include <bits/stdc++.h>
using namespace std;

struct Node {
  int parent;
  vector<int> children;
  int depth;
};

void dfs(vector<Node>& tree, int p, int v) {
  tree[v].parent = p;
  if ( p >= 0 ) tree[v].depth = tree[p].depth+1;
  for ( int c: tree[v].children ) {
    dfs(tree, v, c);    
  }
}

string node_type(Node v) {
  if ( v.parent == -1 ) return "root";
  else if ( v.children.size() == 0 ) return "leaf";
  else return "internal node";
}

int main() {
  int n;
  cin >> n;

  vector<Node> tree(n);
  bool used[n] = {0};  
  for ( int i = 0; i < n; i++ ) {
    int id, k;
    cin >> id >> k;
    for ( int j = 0; j < k; j++ ) {
      int c;
      cin >> c;
      used[c] = true;
      tree[id].children.push_back(c);      
    }
  }

  // calc depth
  for ( int i = 0; i < n; i++ ) {
    if ( !used[i] ) {
      dfs(tree, -1, i);
      break;
    }
  }

  for ( int i = 0; i < n; i++ ) {
    Node v = tree[i];
    printf("node %d: parent = %d, depth = %d, ", i, v.parent, v.depth);
    cout << node_type(v) << ", [";
    for ( int j = 0; j < (int)v.children.size(); j++ ) {
      if ( j ) cout << ", ";
      cout << v.children[j];      
    }
    cout << "]\n";    
  }
  
  return 0;
}

