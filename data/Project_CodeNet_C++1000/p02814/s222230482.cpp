#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

const ll INF = 1e9;
const long long INFL = 1LL<<60;


int main() {
  ll n, m;
  cin >> n >> m;
  ll x = 1;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) {
    if (a[i] % 2 == 1) {
      cout << 0 << endl;
      return 0;
    }
    x = lcm(x, a[i] / 2);
  }

  rep(i, n) {
    if ((2 * x / a[i]) % 2 == 0) {   // 最小公倍数と a[i] で 2^q の q は同じでないといけない
      cout << 0 << endl;
      return 0;
    }
  }

  ll tmp = m / x;
  ll ans = (tmp + 1) / 2;

  cout << ans << endl;

  return 0;
}
