// https://atcoder.jp/contests/abc173/tasks/abc173_c

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DEBUG 1
#if DEBUG
  #define _GLIBCXX_DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

const int H_MAX = 6;
const int W_MAX = 6;

int H, W, K;
vector<string> c;

int main() {
  cin >> H >> W >> K;
  c = vector<string>(H);
  REP(i, H) cin >> c[i];

  int ans = 0;
  int SH = 1 << H;
  int SW = 1 << W;
  REP(sh, SH) REP(sw, SW) {
    int x = 0;
    REP(i, H) {
      if (sh >> i & 1) continue;
      REP(j, W) {
       if (sw >> j & 1) continue;
       if (c[i][j] == '#') x++;
      }
    }
    if (x == K) ans++;
  }
  cout << ans << endl;
}
