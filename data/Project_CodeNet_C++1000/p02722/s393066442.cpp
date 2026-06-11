#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<62;
constexpr double eps = (1e-9);

set<ll> enum_divisor(ll m) {
  set<ll> divisors;
  for (ll i = 1; i*i <= m; ++i) {
    if (m % i != 0) continue;
    divisors.insert(i);
    if (i * i != m) divisors.insert(m / i);
  }
  return divisors;
}

ll solve(const ll& n) {
  auto ans = enum_divisor(n-1);
  ans.erase(1);

  auto divs = enum_divisor(n);
  divs.erase(1);
  for (auto& v : divs) {
    ll m = n;
    while (m % v == 0) {
      m /= v;
    }
    if (m % v == 1) ans.insert(v);
  }

  return ans.size();
}

ll solve2(ll n) {
  set<ll> ans;
  for (int i = 2; i < 200; i++) {
    ll m = n;
    while (m > 1) {
      if (m % i == 0) m /= i;
      else m -= i;
    }
    if (m == 1) ans.insert(i);
  }
  for (auto& x : ans) cerr << x << " "; cerr << endl;
  return ans.size();
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  ll ans = solve(n);
  cout << ans << endl;

  return 0;
}
