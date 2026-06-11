// 2020-08-17 23:02:01
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
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
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  reverse(ALL(s));
  vector<int> a;
  a.push_back(0);
  {
    int x = 0;
    REP(i, 1, s.size()) {
      if(s[i] == '0') {
        a.push_back(a.back() + 1 + x);
        x = 0;
      } else x++;
    }
  }
  vector<int> ans;
  ans.push_back(0);
  REP(i, 1, a.size()) {
    if(a[i] - a[i-1] > m) {
      cout << -1 << '\n';
      return;
    }
    int ci = ans.back();
    if(a[i] - a[ci] <= m) continue;
    ans.push_back(i-1);
  }
  ans.push_back(a.size()-1);
  bool first = true;
  REPCM(i, ans.size()-2, 0) {
    if(first) first = false;
    else cout << ' ';
    cout << a[ans[i+1]] - a[ans[i]];
  }
  cout << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}