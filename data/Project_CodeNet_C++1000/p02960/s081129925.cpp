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

constexpr int mod = 1000000007;

int main() {
  const int N = 13;
  string s;
  cin >> s;

  // 後ろから解くアルゴリズム
  // 1?2?3  0 -> 3 -> ?3 -> 2?3 -> ...

  vector<vector<ll>> dp(s.size() + 1, vector<ll>(N, 0));

  reverse(s.begin(), s.end());

  // 1行目を初期化する
  if (s[0] == '?') {
    for (int i = 0; i < 10; i++) dp[0][i] = 1;
  } else {
    dp[0][s[0] - '0'] = 1;
  }

  ll mul = 10;
  for (int i = 1; i < s.size(); i++) {
    char c = s[i];
    if (c == '?') {
      for (int k = 0; k < 10; k++) {
        for (int j = 0; j < N; j++) {
          dp[i][(k * mul + j) % N] += dp[i-1][j];
          dp[i][(k * mul + j) % N] %= mod;
        }
      }
    } else {
      int k = (int)(c - '0');
      for (int j = 0; j < N; j++) {
        dp[i][(k * mul + j) % N] += dp[i-1][j];
        dp[i][(k * mul + j) % N] %= mod;
      }
    }
    mul *= 10;
    mul %= N;
  }

  cout << dp[s.size()-1][5] << endl;

  return 0;
}
