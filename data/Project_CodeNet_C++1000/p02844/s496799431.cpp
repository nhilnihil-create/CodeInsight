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
  string s;
  cin >> n >> s;

  int ans = 0;

  for (char x = '0'; x <= '9'; x++) {
    auto pos1 = s.find(x);
    if (pos1 == string::npos || pos1 == s.size() - 1) continue;
    for (char y = '0'; y <= '9'; y++) {
      auto pos2 = s.find(y, pos1 + 1);
      if (pos2 == string::npos || pos2 == s.size() - 1) continue;
      for (char z = '0'; z <= '9'; z++) {
        auto pos3 = s.find(z, pos2 + 1);
        if (pos3 == string::npos) continue;
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
