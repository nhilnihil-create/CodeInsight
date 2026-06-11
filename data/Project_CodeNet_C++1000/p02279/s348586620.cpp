#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node { int parent, left, right; };
Node T[MAX];

int getDepth(int u) {
  int d = 0;
  while (T[u].parent != NIL) {
    u = T[u].parent;
    d++;
  }
  return d;
};

vector<int> D(MAX, 0);

void setDepth(int u, int p) {
  D[u] = p;
  if (T[u].right != NIL) {
    setDepth(T[u].right, p);
  }
  if (T[u].left != NIL) {
    setDepth(T[u].left, p + 1);
  }
};

void printChildren(int u) {
  int c = T[u].left;
  cout << '[';
  while (c != NIL) {
    cout << c;
    c = T[c].right;
    if (c != NIL) {
      cout << ", ";
    }
  }
  cout << ']';
};

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    T[i].parent = T[i].right = T[i].left = NIL;
  }

  for (int i = 0; i < n; i++) {
    int id, k;
    cin >> id >> k;
    if (k == 0) {
      T[id].left = NIL;
    } else {
      vector<int> child(k, 0);
      for (int j = 0; j < k; j++) {
        cin >> child[j];
      }
      T[id].left = child[0];
      for (int j = 0; j < k; j++) {
        T[child[j]].parent = id;
        if (j < k - 1) {
          T[child[j]].right = child[j + 1];
        } else {
          T[child[j]].right = NIL;
        }
      }
    }
  }

  int r;

  for (int i = 0; i < n; i++) {
    if (T[i].parent == NIL) r = i;
  }

  setDepth(r, 0);

  for (int i = 0; i < n; i++) {
    cout << "node " << i << ": parent = " << T[i].parent << ", depth = " << D[i];
    if (D[i] == 0) cout << ", root, ";
    else if (T[i].left != NIL) cout << ", internal node, ";
    else cout << ", leaf, ";
    printChildren(i);
    cout << endl;
  }
};

