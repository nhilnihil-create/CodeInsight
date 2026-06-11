#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, s, n) for (int i = (s); i < (n); ++i)
#define rrep(i, n, g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define len(x) (int)(x).size()
#define dup(x, y) (((x) + (y)-1) / (y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  vector<vector<int>> a(3, vector<int>(3));
  rep(i, 0, 3) rep(j, 0, 3) cin >> a[i][j];
  int n;
  cin >> n;
  rep(i, 0, n) {
    int b;
    cin >> b;
    rep(j, 0, 3) rep(k, 0, 3) {
      if (b == a[j][k]) a[j][k] = 0;
    }
  }
  bool ans = false;
  rep(i, 0, 3) {
    if (a[i][0] == 0 && a[i][1] == 0 && a[i][2] == 0) ans = true;
  }
  rep(i, 0, 3) {
    if (a[0][i] == 0 && a[1][i] == 0 && a[2][i] == 0) ans = true;
  }
  if (a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0) ans = true;
  if (a[0][2] == 0 && a[1][1] == 0 && a[2][0] == 0) ans = true;
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}