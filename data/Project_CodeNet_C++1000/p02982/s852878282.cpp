#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)

int d;
int x[12][12];

int is_integer(int i, int j) {
  int dist = 0, inc = 1;
  rep (k, d) dist += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
  rep (inc, 150) if (inc * inc == dist) return 1;
  return 0;
}

int main() {
  int n;
  cin >> n >> d;
  int ans = 0;
  rep (i, n) rep (j, d) cin >> x[i][j];
  rep (i, n) rep (j, i) ans += is_integer(i, j);
  cout << ans << endl;
  return 0;
}