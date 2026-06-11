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

  // 1 4 2 3 5
  // ↓ mod K
  // ↓ -1
  // 0 -1 1 2 0

  // 10 7
  // 14 15 92 65 35 89 79 32 38 46
  //
  // ↓ mod K
  //
  // 0 1 1 2 0 5 2 4 3 4 （和%K = 要素数、という意味は変わらない）
  //
  // ↓ -1 (mod K)
  //
  // 6 0 0 1 6 4 1 3 2 3  (和%K = 0 | ただし要素数 < K)

  // 実際にやってみる
  // 8 4
  // 4 2 4 2 4 2 4 2
  //
  // まず -1 mod K の数列にする
  // 3 1 3 1 3 1 3 1

  // 1つ目の数が0なら数える
  // 2つ目の数では、1つ目にそれを足して、0である数を数える
  // 3つ目の数では、1つ目と2つ目にそれを足し、0を数える
  // ...
  // ただし加算が大変なので、変わりに「0を数える」の「0」をマイナスする
  // ＝判定ラインを下げることで、実質足したみたいにする
  // ...こうすると加算は必要なくなる
  //
  // 3 1 3 1 3 1 3 1
  // 1つ目は3なので、判定ラインは0-3=-3 mod K=1になる。3+1=0(mod K)を追加する。
  // 2つ目は1なので、判定ラインは1-1=0になる。1+0=1を追加する。
  // 1つ目の数が、判定ラインの0と一致するため、リザルトとして1つ数える
  // ...
  //
  // あとは要素数 < K にするために、mapに消費期限を入れていけば良いのではないか

  int N, K;
  cin >> N >> K;
  unordered_map<int, vector<int>> as;
  i64 result = 0;
  int jl = 0; // 判定ライン
  F0R(i, N) {
    int a;
    cin >> a;
    a = (a - 1 + K) % K;
    jl = (jl - a + K) % K;
    a = (a + jl) % K;
    //debug(jl);
    //debug(a);
    as[a].push_back(i);

    int n = lower_bound(rng(as[jl]), i - K + 2) - as[jl].begin();
    result += as[jl].size() - n;
    //debug(result);
  }
  cout << result;
}
#endif
