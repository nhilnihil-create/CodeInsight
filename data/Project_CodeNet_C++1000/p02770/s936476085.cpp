#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
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
  int k, q;
  cin >> k >> q;
  vector<int> d(k);
  rep(i, k) cin >> d[i];
  rep(query, q) {
    int n, x, m;
    cin >> n >> x >> m;
    vector<int> dm(k);
    rep(i, k) dm[i] = d[i]%m;
    int res = n-1;
    ll a = x%m;
    rep(i, k) {
      ll num = (n-1)/k+((n-1)%k > i);
      a += num*dm[i];
      if (!dm[i])
        res -= num;
    }
    res -= a/m;
    cout << res << endl;
  }
  return 0;
}