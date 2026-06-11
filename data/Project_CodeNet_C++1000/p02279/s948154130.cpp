#include<iostream>
#include<string>
using namespace std;

const int N = 100000;
const int NIL = -1;

struct Node {
  int parent, left, right;
};

void set_depth(int id, int d, Node T[], int depth[]) {
  depth[id] = d;
  if (T[id].left != NIL) set_depth(T[id].left, d+1, T, depth);
  if (T[id].right != NIL) set_depth(T[id].right, d, T, depth);
}

void set_type(int n, Node T[], string type[]) {
  for (int i = 0; i < n; i++) {
    if (T[i].parent == NIL) type[i] = "root";
    else if (T[i].left == NIL) type[i] = "leaf";
    else type[i] = "internal node";
  }
}

int main() {
  int i, j, n, id, k, c, child;
  Node Tree[N];
  string type[N];
  int depth[N];

  cin >> n;
  
  // init
  for (i = 0; i < n; i++) {
    Tree[i].parent = NIL;
    Tree[i].left = NIL;
    Tree[i].right = NIL;
  }
  
  // 位置関係をセット
  for (i = 0; i < n; i++) {
    cin >> id >> k;
    for (j = 0; j < k; j++) {
      cin >> c;
      Tree[c].parent = id;
      if (j == 0) {
        Tree[id].left = c;
        child = c;
      } else {
        Tree[child].right = c;
        child = c;
      }
    }
  }

  set_type(n, Tree, type);
  int root = 0;
  for (i = 0; i < n; i++) {
    if (type[i] == "root") root = i;
  }
  set_depth(root, 0, Tree, depth);

  // output
  for (i = 0; i < n; i++) {
    cout << "node " << i << ": parent = " << Tree[i].parent << ", depth = " << depth[i] << ", " << type[i] << ", [";
    int cnt = 0;
    int child = Tree[i].left;
    while (child != NIL) {
      if (cnt > 0) cout << ", ";
      cout << child;
      child = Tree[child].right;
      cnt++;
    }
    cout << "]" << endl;
  }
  
  return 0;
}

