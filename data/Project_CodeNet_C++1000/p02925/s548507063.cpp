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


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n-1));
  rep(i, n) rep(j, n-1) {
    cin >> a[i][j];
    a[i][j]--;
  }
  rep(i, n) reverse(ALL(a[i]));

  ll ans = 0;
  set<int> s;   // 前日試合したリスト
  rep(i, n) s.insert(i);
  while (true) {
    set<pair<int, int>> m;  // ans+1 日目に試合する人たち
    for (auto itr = s.begin(); itr != s.end(); itr++) {
      if (a[*itr].empty()) continue;
      int e = a[*itr].back();
      if (a[e].empty()) continue;
      if (*itr == a[e].back()) m.insert({min(*itr, e), max(*itr, e)});
    }

    if (m.empty()) {  // 誰も試合しない
      rep(i, n) {
        if (!a[i].empty()) {   // 未消化の試合がある
          cout << -1 << endl;
          return 0;
        }
      }
      break;
    }

    s.clear();
    for (auto& p : m) {
      s.insert(p.first);
      s.insert(p.second);
      a[p.first].pop_back();
      a[p.second].pop_back();
    }
    ans++;
  }

  cout << ans << endl;

  return 0;
}
