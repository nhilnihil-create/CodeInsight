/*
 * a.cc: 
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>

using namespace std;

/* constant */

const int MAX_N = 100000;

const string tnames[] = { "root", "internal node", "leaf" };

/* typedef */

typedef vector<int> vi;

/* global variables */

int prts[MAX_N], ds[MAX_N];
vi nbrs[MAX_N];

/* subroutines */

inline int ntype(int id) {
  if (prts[id] < 0) return 0;
  if (nbrs[id].size() == 0) return 2;
  return 1;
}

void rec(int u) {
  vi &nbru = nbrs[u];
  for (vi::iterator vit = nbru.begin(); vit != nbru.end(); vit++) {
    int &v = *vit;
    ds[v] = ds[u] + 1;
    rec(v);
  }
}

/* main */

int main() {
  memset(prts, -1, sizeof(prts));

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int ci;
      cin >> ci;
      nbrs[u].push_back(ci);
      prts[ci] = u;
    }
  }

  int root;
  for (int i = 0; i < n; i++)
    if (prts[i] < 0) {
      root = i;
      break;
    }

  ds[root] = 0;
  rec(root);
  
  for (int i = 0; i < n; i++) {
    printf("node %d: parent = %d, depth = %d, %s, [",
	   i, prts[i], ds[i], tnames[ntype(i)].c_str());
    for (int j = 0; j < nbrs[i].size(); j++) {
      if (j) printf(", ");
      printf("%d", nbrs[i][j]);
    }
    printf("]\n");
  }

  return 0;
}