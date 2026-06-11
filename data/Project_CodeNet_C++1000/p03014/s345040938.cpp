#include <bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;

#define INF (i64)(1e18)
#define MOD (i64)(1e9+7)
#define REP(i, n) for(i64 i = 0; i < (n); i++)
#define RREP(i, n) for(i64 i = (n)-1; i >= 0; i--)
#define RANGE(i, a, b) for(i64 i = (a); i < (b); i++)
#define RRANGE(i, a, b) for(i64 i = (b)-1; i >= (a); i--)
#define ALL(v) (v).begin(), (v).end()
#define SIZE(v) ((i64)(v).size())
template<class T> inline void chmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if (a > b) a = b; }

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i, h) cin >> s.at(i);
  vector<vector<int>> l(h, vector<int>(w)), r(h, vector<int>(w)), d(h, vector<int>(w)), u(h, vector<int>(w));
  REP(i, h) {
    int cnt = 0;
    REP(j, w) {
      if (s[i][j] == '.') {
        cnt++;
        l[i][j] = cnt;
      } else if (s[i][j] == '#') {
        cnt = 0;
      }
    }
  }
  REP(i, h) {
    int cnt = 0;
    RREP(j, w) {
      if (s[i][j] == '.') {
        cnt++;
        r[i][j] = cnt;
      } else if (s[i][j] == '#') {
        cnt = 0;
      }
    }
  }
  REP(j, w) {
    int cnt = 0;
    REP(i, h) {
      if (s[i][j] == '.') {
        cnt++;
        d[i][j] = cnt;
      } else if (s[i][j] == '#') {
        cnt = 0;
      }
    }
  }
  REP(j, w) {
    int cnt = 0;
    RREP(i, h) {
      if (s[i][j] == '.') {
        cnt++;
        u[i][j] = cnt;
      } else if (s[i][j] == '#') {
        cnt = 0;
      }
    }
  }
  int ans = 0;
  REP(i, h) {
    REP(j, w) {
      chmax(ans, l[i][j] + r[i][j] + d[i][j] + u[i][j] - 3);
    }
  }
  cout << ans << endl;

  return 0;
}
