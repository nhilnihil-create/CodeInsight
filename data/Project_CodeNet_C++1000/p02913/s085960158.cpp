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

int calc(const string& s, int l1, int l2, vector<vector<int>>& dp) {
  if (s[l1] != s[l2]) {
    return 0;
  }
  if (dp[l1][l2] != 0) return dp[l1][l2];
  int ans = calc(s, l1 + 1, l2 + 1, dp) + 1;
  chmin(ans, l2 - l1);
  dp[l1][l2] = ans;
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<int>> t(26, vector<int>());
  rep(i, n) {
    t[s[i] - 'a'].push_back(i);
  }

  vector<vector<int>> dp(n, vector<int>(n, 0));

  int ans = 0;
  for (auto& v : t) {            // 26 文字に対して
    if (v.size() < 2) continue;  // 同じ文字が2回以上出てきて無ければその文字はスキップ
    for (int i = 0; i < v.size() - 1; i++) {    // l1
      int l1 = v[i];
      for (int j = i + 1; j < v.size(); j++) {  // l2
        int l2 = v[j];
        int len = calc(s, l1, l2, dp);
        chmax(ans, len);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
