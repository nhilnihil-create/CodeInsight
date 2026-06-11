#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int v, e;
  cin >> v >> e;
  vector<vector<int>> to(v);
  vector<int> ideg(v);
  rep(i, e) {
    int s, t;
    cin >> s >> t;
    to[s].push_back(t);
    ideg[t]++;
  }
  stack<int> st;
  rep(i, v) {
    if (!ideg[i])
      st.push(i);
  }
  vector<int> ts;
  while (!st.empty()) {
    int idx = st.top();
    st.pop();
    ts.push_back(idx);
    for (auto next : to[idx]) {
      ideg[next]--;
      if (!ideg[next])
        st.push(next);
    }
  }
  for (auto e : ts)
    cout << e << endl;
  return 0;
}
