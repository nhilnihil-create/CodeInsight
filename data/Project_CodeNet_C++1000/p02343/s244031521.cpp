#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;
int par[MAXN];
int rank[MAXN];

void init(int n) {
  for (int i=0; i<n; i++) {
    par[i] = i;
    rank[i] = 0;
  }
}

int find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    par[x] = find(par[x]);
    return par[x];
  }
}

void unite(int x,int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return;
  }
  if (rank[x] < rank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rank[x] == rank[y]) {
      rank[x]++;
    }
  }
}

bool same(int x,int y) {
  return find(x) == find(y);
}

int main() {
  int n, q;
  cin >> n >> q;
  init(n);
  for (int i=0; i<q; i++) {
    int com, x, y;
    cin >> com >> x >> y;
    switch (com) {
    case 0:
      unite(x,y);
      break;
    case 1:
      printf("%d\n", same(x,y));
      break;
    default:
      break;
    }
  }
  return 0;
}