#include <iostream>
#include <vector>
using namespace std;

int n;

const int NIL = -1;
struct Node {
  int parent, left, right;
};
vector<Node> T;

int getDepth(int u) {
  int d = 0;
  while (T[u].parent != NIL) {
    u = T[u].parent;
    ++d;
  }
  return d;
}

void printChildren(int u) {
  int c = T[u].left;
  int times = 0;
  while (c != NIL) {
    if (times != 0) cout << ", ";
    cout << c;
    c = T[c].right;
    ++times;
  }
}

string getType(int u) {
  if (T[u].parent == NIL) return "root";
  else if (T[u].left != NIL) return "internal node";
  else return "leaf";
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  T.reserve(n);
  for (int i = 0; i < n; ++i) {
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
  }
  for (int i = 0; i < n; ++i) {
    int id;
    cin >> id;
    int k;
    cin >> k;
    int prev_child;
    for (int j = 0; j < k; ++j) {
      int child;
      cin >> child;
      if (j == 0) T[id].left = child;
      T[child].parent = id;
      if (j != 0) T[prev_child].right = child;
      prev_child = child;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << "node " << i << ": parent = " << T[i].parent << ", depth = " << getDepth(i) << ", "
    << getType(i) << ", [";
    printChildren(i);
    cout << "]" << endl;
  }
}

