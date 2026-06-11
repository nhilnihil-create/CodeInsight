#include <iostream>
#include <string>
using namespace std;

struct Node {
  int parent;
  int r_sibling;
  int l_child;
  int depth;
};

Node T[100000];
const int NIL = -1;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    T[i].parent = T[i].r_sibling = T[i].l_child = NIL;
  }

  for (int i = 0; i < n; i++) {
    int id, degree;
    cin >> id >> degree;
    for (int j = 0; j < degree; j++) {
      if (j == 0) {
        cin >> T[id].l_child;
        id = T[id].l_child;
      } else {
        cin >> T[id].r_sibling;
        id = T[id].r_sibling;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (T[i].l_child == NIL) continue;
    int cid = T[i].l_child;
    T[cid].parent = i;
    while (1) {
      if (T[cid].r_sibling == NIL) break;
      T[T[cid].r_sibling].parent = T[cid].parent;
      cid = T[cid].r_sibling;
    }
  }

  for (int i = 0; i < n; i++) {
    int d = 0;
    int pn = T[i].parent;
    while(1) {
      if (pn == NIL) {
        T[i].depth = d;
        break;
      }
      d++;
      pn = T[pn].parent;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << "node " << i << ": ";
    cout << "parent = " << T[i].parent << ", ";
    cout << "depth = " << T[i].depth << ", ";
    //cout << "l = " << T[i].l_child << ", ";
    //cout << "r = " << T[i].r_sibling << ", ";

    if (T[i].parent == NIL) {
      cout << "root";
    } else if (T[i].l_child == NIL) {
      cout << "leaf";
    } else {
      cout << "internal node";
    }
    cout << ", ";

    cout << "[";
    int cn = T[i].l_child;
    while(1) {
      if (cn == NIL) break;
      if (cn != T[i].l_child) cout << ", ";
      cout << cn;
      cn = T[cn].r_sibling;
    }
    cout << "]";
    cout << endl;
  }

  return 0;
}