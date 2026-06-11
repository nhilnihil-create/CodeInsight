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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, t;
  cin >> n >> t;
  vector<pair<int, int>> dish;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    dish.push_back({a, b});
  }
  sort(ALL(dish));

  // i 番目までの料理を t-1 秒までに完食した場合の美味しさの最大値
  vector<vector<int>> dp(n, vector<int>(t, 0));
  for (int j = dish[0].first; j < t; j++) dp[0][j] = dish[0].second;  // 0 番目の料理だけ食べる

  for (int i = 1; i < n; i++) {
    int a = dish[i].first;
    int b = dish[i].second;
    for (int j = 0; j < t; j++) {
      if (j - a >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-a] + b);
      else dp[i][j] = dp[i-1][j];
    }
  }

  int ans = dish[0].second;
  for (int i = 1; i < n; i++) {
    chmax(ans, dp[i-1][t-1] + dish[i].second);
  }

  cout << ans << endl;

  return 0;
}
