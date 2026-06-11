#include <iostream>
#define MAX_N 10000
using namespace std;

int par[MAX_N];
int rank[MAX_N];

int find(int x) {
  if (par[x] == x) return x;
  return find(par[x]);
}

bool same(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return true;
  return false;
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;

  if (rank[x] < rank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
  }

  if (rank[x] == rank[y]) rank[x]++;
}

void init(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    rank[i] = 0;
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  init(n);

  for (int i = 0; i < q; i++) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      unite(x, y);
    } else {
      if (same(x, y)) cout << 1 << endl;
      else cout << 0 << endl;
    }
  }

  return 0;
}