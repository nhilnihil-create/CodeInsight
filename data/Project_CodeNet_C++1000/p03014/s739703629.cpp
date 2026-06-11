// 2020-07-05 15:52:12
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
  int h, w;
  cin >> h >> w;
  vector<vector<int> > wall(h, vector<int>(w, 0));
  rep(hi, h) {
    string s;
    cin >> s;
    rep(wi, w) if(s[wi] == '#') wall[hi][wi] = 1;
  }
  vector<vector<int> > sumh(h, vector<int>(w, 0));
  vector<vector<int> > sumw(h, vector<int>(w, 0));
  rep(hi, h) {
    vector<int> sum(w+1, 0);
    rep(wi, w) {
      if(wall[hi][wi]) sum[wi+1] = 0;
      else sum[wi+1] = sum[wi] + 1;
    }
    REPCM(wi, w-1, 0) {
      if(wall[hi][wi]) {
        sumw[hi][wi] = 0;
      } else {
        sumw[hi][wi] = sum[wi+1];
        sum[wi] = sum[wi+1];
      }
    }
  }
  rep(wi, w) {
    vector<int> sum(h+1, 0);
    rep(hi, h) {
      if(wall[hi][wi]) sum[hi+1] = 0;
      else sum[hi+1] = sum[hi] + 1;
    }
    REPCM(hi, h-1, 0) {
      if(wall[hi][wi]) {
        sumh[hi][wi] = 0;
      } else {
        sumh[hi][wi] = sum[hi+1];
        sum[hi] = sum[hi+1];
      }
    }
  }
  int ans = 0;
  rep(hi, h) rep(wi, w) chmax(ans, sumh[hi][wi] + sumw[hi][wi] - 1);
  cout << ans << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}