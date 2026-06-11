#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
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

constexpr int INF = 1e9 + 5;
constexpr long long INFLL = 1LL << 62;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  reverse(ALL(s));
  vector<int> ns(n+1, 0);   // 自分とその手前で，直近の安全なマス
  int tmp = 0;
  rep(i, n+1) {
    if (s[i] == '0') {
      ns[i] = i;
      tmp = i;
    } else {
      ns[i] = tmp;
    }
  }

  int cur = 0;
  vector<int> ans;
  while (true) {
    int next = cur + m;
    if (next >= n) {
      ans.push_back(n-cur);
      break;
    }
    if (s[next] == '0') {
      ans.push_back(next - cur);
      cur = next;
    } else {
      next = ns[next];
      if (cur == next) {
        cout << -1 << endl;
        return 0;
      } else {
        ans.push_back(next - cur);
        cur = next;
      }
    }
  }

  reverse(ALL(ans));

  for (auto& x : ans) cout << x << " "; cout << endl;

  return 0;
}
