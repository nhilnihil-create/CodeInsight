#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  vector<vector<int>> a(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> a[i][j];
  int n;
  cin >> n;
  vector<int> b(n);
  rep(i, n) cin >> b[i];
  
  bool bingo = false;
  int s;
  rep(i, n) rep(j, 3) rep(k, 3) if (b[i] == a[j][k]) a[j][k] = 0;
  rep(i, 3) {
    s = 0;
    rep(j, 3) s += a[i][j];
    if (s == 0) bingo = true;
    s = 0;
    rep(j, 3) s += a[j][i];
    if (s == 0) bingo = true;
  }
  s = 0;
  rep(i, 3) s += a[i][i];
  if (s == 0) bingo = true;
  s = 0;
  rep(i, 3) s += a[i][2-i];
  if (s == 0) bingo = true;
  if (bingo) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}