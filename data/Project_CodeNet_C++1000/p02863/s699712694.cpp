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

  // T-1分以内に食べ終わる最大のおいしさを求める
  // そのあとDPの表を逆にたどり、使った料理を求め、それ以外で一番おいしさが高い物を足して解とする

  // ただし普通にたどるだけだと、最適解が求まらないことがある

  // テストケース1
  // 3 5
  // 4 400
  // 2 200
  // 2 200

  // テストケース2
  // 3 5
  // 2 200
  // 4 400
  // 2 200

  // テストケース3
  // 3 5
  // 2 200
  // 2 200
  // 4 400

  // これらは全て800とならないといけないが、いずれかで600になってしまう。
  // T-1分以内に完食する最大おいしさを、実現できる手段が複数ある場合、
  // 普通の方法だとそのうちいずれか1種類を求めるアルゴリズムになるので、
  // 手段ごとに最後に残った料理の最大値が違う場合に、最適解が得られないケースが出る。

  // ① 辿り方自体を工夫する
  // ② 今の辿り方でうまく動くようにする
  //
  // ②。今の辿り方の特性から、美味しさの事前降順ソートでうまくいきそうなのでやってみる

  // 結果、上記テストケース3つは解決できるが、after_contest_01でWAなのは変わらず。
  
  // テストケース4
/*
3 5
2 2
2 2
4 6
*/
  // この解は10であるべきだが、8になる。
  // T-1分以内での最大美味しさが 6 で、その後最終注文を 2 と決めるので 8 になるが、
  // 実際はT-1分以内に 2+2=4 食べて、最終を 6 にしたほうが 10 と高くなることが分かる
/*
4 105
2 2
2 2
4 6
100 100
*/
  // これも110になるべきところが108になるので、
  // 「美味しさ最大の料理だけ別扱いする」という場当たり的対策では足りない。

  // ・解説を読む

  // 右からのDPと左からのDPを用意して、各料理を最後に頼む場合を全探索する

  int N, T;
  cin >> N >> T;
  vector<int> as(N), bs(N);

  F0R(i, N) {
    cin >> as[i] >> bs[i];
  }

  vector<vector<int>> dp1(N + 1, vector<int>(T)), dp2(N + 1, vector<int>(T));

  F0R(i, N) {
    F0R(j, min(as[i], T)) {
      dp1[i + 1][j] = dp1[i][j];
    }
    FOR(j, as[i], T) {
      dp1[i + 1][j] = max(dp1[i][j], dp1[i][j - as[i]] + bs[i]);
    }
  }

  RF0(i, N) {
    F0R(j, min(as[i], T)) {
      dp2[i][j] = dp2[i + 1][j];
    }
    FOR(j, as[i], T) {
      dp2[i][j] = max(dp2[i + 1][j], dp2[i + 1][j - as[i]] + bs[i]);
    }
  }

  int result = 0;
  F0R(i, N) {
    int score = 0;
    F0R(j, T) {
      chmax(score, dp1[i][j] + dp2[i + 1][T - 1 - j]);
    }
    chmax(result, score + bs[i]);
  }
  cout << result;
}
#endif
