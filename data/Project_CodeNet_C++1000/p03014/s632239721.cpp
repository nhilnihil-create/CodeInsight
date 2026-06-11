#pragma GCC optimize("Ofast")
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

constexpr char newl = '\n';
constexpr double eps = 1e-10;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = ((b)-1); i >=(a); i--)
#define RF0(i,b) RFO(i,0,b)
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << '\n';
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()

template<typename T1, typename T2> inline void chmin(T1& a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
template<class T> void Print(vector<T> v) {
  F0R(i, v.size()) {
    cout << v[i] << ' ';
  }
  cout << newl;
}

#if 1


// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int H, W;
  cin >> H >> W;
  vector<string> ss(H);
  F0R(i, H) {
    cin >> ss[i];
  }

  vector<vector<int>> hs(H, vector<int>(W)), vs(H, vector<int>(W));
  F0R(i, H) {
    int l = 0, a = 0;
    F0R(j, W) {
      if (ss[i][j] == '.') {
        if (!a++) {
          l = j;
        }
        else {
          hs[i][j] = -(a-1);
        }
      }
      else {
        if (a) {
          hs[i][j - a] = a;
          a = 0;
        }
      }
    }
    if (a) {
      hs[i][W - a] = a;
    }
  }
  F0R(c, W) {
    int l = 0, a = 0;
    F0R(r, H) {
      if (ss[r][c] == '.') {
        if (!a++) {
          l = r;
        }
        else {
          vs[r][c] = -(a - 1);
        }
      }
      else {
        if (a) {
          vs[r - a][c] = a;
          a = 0;
        }
      }
    }
    if (a) {
      vs[H - a][c] = a;
    }
  }
  int result = 0;
  F0R(r, H) {
    F0R(c, W) {
      int score = -1;
      score += hs[r][c] < 0 ? hs[r][c + hs[r][c]] : hs[r][c];
      score += vs[r][c] < 0 ? vs[r + vs[r][c]][c] : vs[r][c];
      chmax(result, score);
    }
  }
  cout << result;
}
#endif
