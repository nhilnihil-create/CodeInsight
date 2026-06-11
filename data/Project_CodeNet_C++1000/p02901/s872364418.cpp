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

struct GetNumberOfTrailingZeros {
  constexpr GetNumberOfTrailingZeros() : table() {
    uint64_t hash = 0x03F566ED27179461UL;

    for (int i = 0; i < 64; i++)
    {
      table[hash >> 58] = i;
      hash <<= 1;
    }
  }
  int Calc(int64_t x)
  {
    if (x == 0) return 64;

    uint64_t y = (uint64_t)(x & -x);
    int i = (int)((y * 0x03F566ED27179461UL) >> 58);
    return table[i];
  }
  int table[64];
} gntz;


// INSERT ABOVE HERE
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int N, M;
  cin >> N >> M;
  vector<int> as(M);
  vector<int> bs(M);
  F0R(i, M) {
    int a, b;
    cin >> a >> b;
    as[i] = a;
    F0R(j, b) {
      int c;
      cin >> c;
      c--;
      bs[i] |= 1 << c;
    }
  }

  vector<vector<int>> dp(M + 1, vector<int>(1 << N, 1000001));
  dp[0][0] = 0;

  F0R(i, M) {

    int ib = ~bs[i];
    F0R(j, 1 << N) {
      dp[i + 1][j] = min(dp[i][j], dp[i][j & ib] + as[i]);
    }
  }

  int r = dp[M][(1 << N) - 1];
  if (r > 1000000) r = -1;
  cout << r;
}
#endif
