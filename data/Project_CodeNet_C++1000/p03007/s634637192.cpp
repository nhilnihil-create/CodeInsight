#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end());
  vector<pair<int, int>> ans;
  int res1 = a[0], idx1 = lower_bound(a.begin(), a.end(), 0) - a.begin();
  chmax(idx1, 1);
  FOR(i, idx1, n - 1) {
    ans.push_back({res1, a[i]});
    res1 -= a[i];
  }
  int res2 = a[n - 1], idx2 = lower_bound(a.begin(), a.end(), 0) - a.begin();
  chmin(idx2, n - 1);
  FOR(i, 1, idx2) {
    ans.push_back({res2, a[i]});
    res2 -= a[i];
  }
  ans.push_back({res2, res1});
  int sum = res2 - res1;
  cout << sum << endl;
  rep(i, n - 1) cout << ans[i].first << ' ' << ans[i].second << endl;


  
  return 0;
}