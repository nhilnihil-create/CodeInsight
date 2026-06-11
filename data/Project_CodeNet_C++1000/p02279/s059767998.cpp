#include <bits/stdc++.h>

#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

#define MAX_N 100000
#define NIL -1
#define ROOT 0
#define LEAF 1
#define INTERNAL 2

// left-child, right-sibling representation
struct Node {
  int parent, left, right;
};

Node T[MAX_N + 5];
int D[MAX_N + 5];

void setDepth(int i, int d) {
  D[i] = d;
  if (T[i].right != NIL) setDepth(T[i].right, d);
  if (T[i].left != NIL) setDepth(T[i].left, d + 1);
}

int getType(Node n) {
  if (n.parent == NIL)
    return ROOT;
  else if (n.left == NIL)
    return LEAF;
  else
    return INTERNAL;
}

string convertType(int n) {
  if (n == ROOT)
    return "root";
  else if (n == LEAF)
    return "leaf";
  else
    return "internal node";
}

void printChild(int i) {
  if (T[i].left == NIL) return;
  int n = T[i].left;
  int cnt = 0;
  while (n != NIL) {
    if (cnt > 0) cout << ", ";
    cout << n;
    n = T[n].right;
    cnt++;
  }
}

void printNode(int i) {
  printf("node %d: parent = %d, depth = %d, ", i, T[i].parent, D[i]);
  cout << convertType(getType(T[i])) << ", [";
  printChild(i);
  cout << "]" << endl;
}

int findRoot(int n) {
  rep(i, n) if (getType(T[i]) == ROOT) return i;
  return -1;
}

int main() {
  int n;
  cin >> n;
  // initialize T
  rep(i, n) {
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
  }

  rep(i, n) {
    int p_id, k;
    cin >> p_id >> k;
    int prev = NIL;
    rep(j, k) {
      int c_id;
      cin >> c_id;
      T[c_id].parent = p_id;
      if (j == 0) T[p_id].left = c_id;
      if (j > 0) T[prev].right = c_id;
      prev = c_id;
    }
  }
  setDepth(findRoot(n), 0);
  rep(i, n) printNode(i);
  return 0;
}

