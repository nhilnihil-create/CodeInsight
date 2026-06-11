#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFLL = LLONG_MAX / 3;
const double eps = (1e-9);


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  vector<string> ans;
  using P = pair<string, int>;
  queue<P> q;
  q.push(P("a", 1));

  while (!q.empty()) {
    P p = q.front(); q.pop();
    if (p.first.size() == n) {
      ans.push_back(p.first);
      continue;
    }
    for (int i = 0; i < p.second + 1; i++) {
      string s = p.first;
      s.push_back('a' + i);
      if (i < p.second) q.push(P(s, p.second));
      else q.push(P(s, p.second + 1));
    }
  }

  for (auto& s : ans) {
    cout << s << endl;
  }

  return 0;
}
