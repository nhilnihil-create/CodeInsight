#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i, n) cin >> x[i] >> y[i];
  vector<int> idx(n);
  iota(idx.begin(), idx.end(), 0);
  int fac = 1;
  for (int i = 2; i <= n; i++)
    fac *= i;
  double ans = 0;
  do {
    double res = 0;
    rep(i, n-1) {
      int dix = x[idx[i+1]]-x[idx[i]];
      int diy = y[idx[i+1]]-y[idx[i]];
      res += sqrt(dix*dix+diy*diy);
    }
    res /= fac;
    ans += res;
  } while (next_permutation(idx.begin(), idx.end()));
  cout << fixed << setprecision(9) << ans << endl;
  return 0;
}
