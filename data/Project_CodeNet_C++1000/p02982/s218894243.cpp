#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()
#define sqr(x) ((x)*(x))

double dist(vector<double> &a, vector<double> &b) {
  double ret = 0;
  for (int i = 0; i < a.size(); i++) {
    ret += sqr(a[i] - b[i]);
  }
  return sqrt(ret);
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector<vector<double>> v(n, vector<double>(d));
  for (auto &i : v) for (auto &j : i) cin >> j;
  int ans = 0;
  for (int i = 0; i < n - 1; i++)
  for (int j = i + 1; j < n; j++) {
    double t = dist(v[i], v[j]);
    if (abs(t - trunc(t)) < 1e-6) ans++;
  }
  cout << ans << '\n';
}
