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
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

void dfs(const vector<vector<int>>& ki, vector<ll>& counter, const int& p, const int& pp) {
  for (auto& c : ki[p]) {
    if (c == pp) continue;
    counter[c] += counter[p];
    dfs(ki, counter, c, p);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  vector<vector<int>> ki(n);
  rep(i, n-1) {
    int a, b; cin >> a >> b; a--; b--;
    ki[a].push_back(b);
    ki[b].push_back(a);
  }

  vector<ll> counter(n, 0);
  rep(i, q) {
    int p, x;
    cin >> p >> x;
    p--;
    counter[p] += x;
  }

  dfs(ki, counter, 0, -1);

  for (auto& x : counter) cout << x << " "; cout << endl;

  return 0;
}
