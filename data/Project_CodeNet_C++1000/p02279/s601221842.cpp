#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
const int NIL = -1;

struct Node { int parent, left, right;};
struct Node T[MAX];
int n, D[MAX];

void print(int u) {
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].parent << ", ";
  cout << "depth = " << D[u] << ", ";

  if (T[u].parent == NIL) cout << "root, ";
  else if (T[u].left == NIL) cout << "leaf, ";
  else cout << "internal node, ";

  cout << "[";
  int cur = T[u].left;
  while (cur != NIL) {
    cout << cur;
    cur = T[cur].right;
    if (cur == NIL) break;
    cout << ", ";
  }
  cout << "]" << endl;
}

void rec(int u, int p) {
  D[u] = p;
  if (T[u].right != NIL) rec(T[u].right, p);
  if (T[u].left != NIL) rec(T[u].left, p + 1);
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    T[i].parent = T[i].left = T[i].right = NIL;
  }

  for (int i = 0; i < n; i++) {
    int u, m;
    cin >> u >> m;
    int prev = NIL;
    for (int j = 0; j < m; j++) {
      int c;
      cin >> c;
      T[c].parent = u;
      if (prev == NIL) T[u].left = c;
      else T[prev].right = c;
      prev = c;
    }
  }
  
  int root = NIL;
  for (int i = 0; i < n; i++) {
    if (T[i].parent == NIL) {
      root = i;
      break;
    }
  }
  rec(root, 0);

  for (int i = 0; i < n; i++) {
    print(i);
  }
}
