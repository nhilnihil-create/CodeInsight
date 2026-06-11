// 2020-07-24 01:34:17
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  using P = pair<int, int>;
  int n;
  cin >> n;
  vector<vector<int> > a(n, vector<int>(n, -1));
  rep(i, n) {
    rep(j, n-1) {
      cin >> a[i][j];
      a[i][j]--;
    }
    a[i][n-1] = i;
  }
  set<P> st;
  auto add = [&](int i, int j) {
    st.insert(make_pair(min(i, j), max(i, j)));
  };
  rep(i, n) {
    int j = a[i][0];
    if(a[j][0] == i) add(i, j);
  }
  vector<int> c(n, 0);
  int ans = 0, done = 0;
  while(done < n) {
    ans++;
    set<P> p;
    swap(p, st);
    if(p.empty()) {
      cout << -1 << '\n';
      return;
    }
    for(const auto& el : p) {
      int u, v;
      tie(u, v) = el;
      c[u]++;
      c[v]++;
      for(int i : {u, v}) {
        if(a[i][c[i]] == i) done++;
        else {
          int j = a[i][c[i]];
          if(a[j][c[j]] == i) add(i, j);
        }
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}