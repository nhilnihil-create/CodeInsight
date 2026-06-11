#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// ---------------------
// repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

// debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

// ---------------------
#define INF 922337203685477580
typedef long long ll;

#define NIL -1

typedef struct {
  int parent, left, right;
} Node;


Node T[100100];
int D[100100];


void depth(int key, int d) {
  if (key == NIL) return;
  for (int right = key; right != NIL; right = T[right].right) {
    D[right] = d;

    depth(T[right].left, d + 1);
  }
}

int main() {
  int n;
  cin >> n;
  // Node T[n + 10];

  REP(i, n + 10) {
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
  }

  REP(i, n) {
    int key, num_child;
    cin >> key;
    cin >> num_child;

    int child[num_child];

    FOR(j, 0, num_child) {
      cin >> child[j];
      T[key].left = child[0];
    }

    FOR(j, 0, num_child) {
      T[child[j]].parent = key;

      if (j < num_child - 1) {
        T[child[j]].right = child[j + 1];
      }
    }
  }

  // calc depth
  REP(i, n) {
    if (T[i].parent == NIL) {
      depth(i, 0);
      break;
    }
  }


  REP(i, n) {
    string role;
    if (T[i].parent == NIL) {
      role = "root";
    } else if (T[i].left != NIL) {
      role = "internal node";
    } else {
      role = "leaf";
    }
    cout << "node " << i << ": parent = " << T[i].parent << ", depth = " << D[i] << ", " << role << ", ";

    int j = 0;
    cout << "[";
    for (int child = T[i].left; child != NIL; child = T[child].right) {
      if (j++) cout << ", ";
      cout << child;
    }
    cout << "]" << endl;
  }

  return 0;
}