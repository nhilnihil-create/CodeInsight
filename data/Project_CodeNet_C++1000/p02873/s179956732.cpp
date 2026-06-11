#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define DUMP(v) for(auto& x : v) cerr << x << " "; cerr << endl;
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  vector<int> a(s.size() + 1, 0);
  a[0] = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '<') chmax(a[i+1], a[i] + 1);
  }

  for (int i = s.size()-1; i >= 0; i--) {
    if (s[i] == '>') chmax(a[i], a[i+1] + 1);
  }

  ll ans = SUM(a);
  cout << ans << endl;

  return 0;
}
