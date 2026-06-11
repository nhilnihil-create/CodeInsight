#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int n, d, ans;
double dist;

int main() {
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  rep (i, n) {
    rep (j, d) {
      cin >> x[i][j];
    }
  }
  ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      dist = 0;
      rep (k, d) {
        dist += pow((double)(x[i][k]-x[j][k]), 2);
      }
      rep (i, 401) {
        if (dist == i*i) ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
