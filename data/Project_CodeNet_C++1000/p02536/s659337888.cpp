#include <iostream>
#include <cstdio>

using namespace std;

int par[100005];

void init(int n) {
  for (int i = 0; i <= n; i++) {
    par[i] = i;
  }
  return ;
}

int ffind(int x) {
  return par[x] = (par[x] == x ? x : ffind(par[x]));
}

bool same(int a, int b) {
  if (ffind(a) == ffind(b)) return true;
  return false;
}

void unite(int x, int y) {
  if (same(x, y)) return ;
  int xx = ffind(x), yy = ffind(y);
  par[xx] = yy;
  return ;
}

int main() {
  int n, m;
  cin >> n >> m;
  init(n);
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    unite(a, b);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (par[i] == i) ans++;
  }
  cout << ans - 1 << endl;
  return 0;
}