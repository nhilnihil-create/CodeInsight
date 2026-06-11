#include <iostream>
using namespace std;
#define NIL -1

struct node {
  int parent;
  int left;
  int right;
};

node tree[100001];

int getDepth(int n) {
  int d = 0;
  while (tree[n].parent != NIL) {
    d++;
    n = tree[n].parent;
  }
  return d;
}

int main() {
  int n, id, k, tmp;
  int d[100001];
  cin >> n;
  for (int i = 0; i < n; i++) {
    tree[i].parent = tree[i].left = tree[i].right = NIL;
  }
  for (int i = 0; i < n; i++) {
    cin >> id >> k;
    if (k > 0) {
      int ch;
      for (int j = 0; j < k; j++) {
        cin >> ch;
        if (j == 0) {
          tree[id].left = ch;
        } else {
          tree[tmp].right = ch;
        }
        tree[ch].parent = id;
        tmp = ch;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    d[i] = getDepth(i);
    cout << "node " << i << ": ";
    cout << "parent = " << tree[i].parent << ", ";
    cout << "depth = " << d[i] << ", ";
    if (tree[i].parent == NIL) {
      cout << "root";
    } else if (tree[i].left == NIL) {
      cout << "leaf";
    } else {
      cout << "internal node";
    }
    cout << ", [";
    if (tree[i].left != NIL) {
      int c = tree[i].left;
      cout << c;
      c = tree[c].right;
      while (c != NIL) {
        cout << ", " << c;
        c = tree[c].right;
      }
    }
    cout << "]" << endl;
  }
}
