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

  // 1回ずつ最適な変更をすればいいわけではない。
  //
  //   *
  //  ***
  // *****
  //
  // たとえばこの例だと、1回の操作では中央を1減らすのが良いが、
  // 3回の操作をするなら全部1段になるのがベストなので、中央は2減らさないといけない。

  // K == N の場合、全てを0にすれば良い。
  // K < N のとき、HiはHjに変更する、と考える。
  // このとき、変更する区間とHjは必ず隣接する。（隣と高さを合わせることで、操作数を減らすことができるから）
  // 変更する部分が孤立しているとき、Hjはその左右どちらかであるし、
  // 変更する部分が複数隣接する場合は、Hjはその区間の左右どちらかになる。

  // K 回以下の変更で、操作回数を可能な限り削減せよ。

  // 操作回数の数え方。O(N)

  //    *
  //  * *
  //  *** *
  // **** *
  // **** *  *
  // ****** **
  // *********
  //
  // この操作回数は13回。
  // 全てのHiに対し、一つ前のHiとの差の数列にし、そのうち正の数のみの合計を取る。
  // ただしH0は0とする
  //
  // 上の例だと、数列は
  // 4,2,-1,2,-5,3,-4,1,1
  // 正の数のみ足すと、操作回数の13が得られる。 

  // 1回（1区間）の変更で、どれだけ操作回数が削減できるか？
  // 上の例で、左右をのぞいた中全てを変更すると考える。
  // すると操作回数は4回にできる。
  //
  // ********
  // *********
  // *********
  // *********
  //
  // 操作回数の観点でいえば、変更された部分が存在しないと考えても同じである。
  // つまり、変更された部分は削除され、以下になると考える。
  //
  // *
  // **
  // **
  // **
  
  // よって、問題はこうなる。
  // 「K列消して、操作回数を最小にせよ。」

  i64 result = 0;

  int N, K;
  cin >> N >> K;
  vector<int> hs(N+2);
  F0R(i, N) {
    cin >> hs[i+1];
    result += max(hs[i + 1] - hs[i], 0);
  }

  // dp[i][j] := i列目までを、K列消したときの、減らせる操作回数の最大値
  vector<vector<i64>> dp(N + 1, vector<i64>(K + 1));

  FOR(i, 1, N+1) { // 消し始める列

    FOR(j, 1, min(i + 1, K+1)) {
      chmax(dp[i][j], dp[i - 1][j]);
    }

    i64 sum = max(hs[i] - hs[i-1], 0);

    // i列から連続で消す数-1
    F0R(j, min(K, N - i + 1)) {
      sum += max(hs[i + j + 1] - hs[i + j], 0);
      i64 score = sum - max(hs[i + j + 1] - hs[i - 1], 0);
      //debug(score);

      if (i >= 2) {
        F0R(k, K - j) {
          chmax(dp[i + j][j + 1 + k], score + dp[i - 2][k]);
        }
      }
      else {
        chmax(dp[i + j][j + 1], score);
      }
    }
    //Print(dp[i]);
  }

  result -= dp[N][K];

  cout << result;
}
#endif
