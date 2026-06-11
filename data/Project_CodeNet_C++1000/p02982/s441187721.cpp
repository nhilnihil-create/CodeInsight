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
  int n, d;
  cin >> n >> d;
  Field(int) z(n, vector<int>(d));
  rep(i, 0, n) rep(j, 0, d) cin >> z[i][j];
  int ans = 0;
  rep(i, 0, n - 1) rep(j, i + 1, n) {
    int check = 0;
    rep(k, 0, d) check += (z[i][k] - z[j][k]) * (z[i][k] - z[j][k]);
    if (sqrt(check) == (int)sqrt(check)) ans++;
  }
  cout << ans << endl;
  return 0;
}