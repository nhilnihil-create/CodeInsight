#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m, l;
  cin >> n >> m >> l;
  int a[n][m], b[m][l];
  ll c[n][l] = {};
  rep(i, n) rep(j, m) cin >> a[i][j];
  rep(i, m) rep(j, l) cin >> b[i][j];

  rep(i, n) {
    rep(j, l) {
      rep(k, m) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  rep(i, n) {
    rep(j, l) {
      cout << c[i][j];
      if (j != l - 1)
        cout << " ";
    }
    cout << endl;
  }

  return 0;
}
