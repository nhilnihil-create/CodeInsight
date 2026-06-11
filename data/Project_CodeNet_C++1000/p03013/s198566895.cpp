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
constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

constexpr int mod = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  set<int> broken;
  rep(i, m) {
    int b; cin >> b;
    broken.insert(b);
  }

  vector<ll> dp(n+2, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    if (!broken.count(i+1)) {
      dp[i+1] += dp[i];
      dp[i+1] %= mod;
    }
    if (!broken.count(i+2)) {
      dp[i+2] += dp[i];
      dp[i+2] %= mod;
    }
  }

  cout << dp[n] << endl;

  return 0;
}
