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

  int N, K;
  cin >> N >> K;

  // 最短距離2である頂点対の数
  // 数珠つなぎ *-*-*-*
  // N-2
  // スターグラフ これが上限？
  // (N-1)(N-2)/2

  if (K > (N - 1) * (N - 2) / 2) {
    cout << -1;
    return 0;
  }

  int m = N * (N - 1) / 2 - K;
  cout << m << newl;

  // まず0から放射状にスターグラフ
  FOR(i, 1, N) {
    cout << "1 " << (i + 1) << newl;
  }

  // それ以降は、Kの数だけ繋がず、他は全部つなぐ
  FOR(i, 1, N) {
    FOR(j, i + 1, N) {
      if (K) {
        K--;
        continue;
      }

      cout << (i + 1) << " " << (j + 1) << newl;
    }
  }
}
#endif
