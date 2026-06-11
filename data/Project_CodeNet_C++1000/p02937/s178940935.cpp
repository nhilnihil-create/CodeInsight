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
constexpr int INF = 1e9;
constexpr long long INFLL = 1LL<<60;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s, t;
  cin >> s >> t;

  vector<vector<int>> pos(26, vector<int>());
  for (int i = 0; i < s.size(); i++) {
    pos[s[i] - 'a'].push_back(i);
  }

  int idx = 0;  // 次の文字を探し始める場所
  ll num = 0;
  ll ans = 0;
  for (char& c : t) {
    auto itr = lower_bound(ALL(pos[c - 'a']), idx);
    if (idx != 0 && itr == pos[c - 'a'].end()) {
      idx = 0;
      num++;
      itr = lower_bound(ALL(pos[c - 'a']), idx);
    }
    if (itr == pos[c - 'a'].end()) {
      cout << -1 << endl;
      return 0;
    }
    ans = s.size() * num + *itr + 1;
    idx = *itr + 1;
  }

  cout << ans << endl;

  return 0;
}
