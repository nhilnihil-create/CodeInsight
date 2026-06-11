#pragma GCC optimize("O3") //コンパイラ最適化用

#define _GLIBCXX_DEBUG //配列に[]でアクセス時のエラー表示
#include <algorithm>   //sort,二分探索,など
#include <bitset>      //固定長bit集合
#include <chrono>      //実行時間計測
#include <cmath>       //pow,logなど
#include <complex>     //複素数
#include <deque>       //両端アクセスのキュー
#include <functional>  //sortのgreater
#include <iomanip>     //setprecision(浮動小数点の出力の誤差)
#include <iostream>    //入出力
#include <iterator>    //集合演算(積集合,和集合,差集合など)
#include <map>         //map(辞書)
#include <numeric>     //iota(整数列の生成),gcdとlcm,accumulate
#include <queue>       //キュー
#include <set>         //集合（順序保持）
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility> //pair
#include <vector>  //可変長配列
using namespace std;
typedef long long ll;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < ll(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < ll(b); i++)
#define FORD(i, a, b) for (int i = a; i > ll(b); i--)
// xにはvectorなどのコンテナ
#define ALL(x) x.begin(), x.end()
#define SIZE(x) ll(x.size()) // sizeをsize_tからllに直しておく

#define INF 1000000000000 // 10^12:極めて大きい値,∞
const int MOD = 1000000007;
#define MAXR 100000 // 10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define Umap unordered_map
#define Uset unordered_set
const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000

void add(long long &a, long long b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {

    int n, time_limit;
    cin >> n >> time_limit;
    vector<vector<int>> time_pleasure(n, vector<int>(2, 0));
    REP(i, n) {
        int a, b;
        cin >> a >> b;
        time_pleasure[i][0] = a;
        time_pleasure[i][1] = b;
    }

    // 第i列を軸にしてvvをソート
    sort(ALL(time_pleasure),
         [](const vector<int> &alpha, const vector<int> &beta) {
             return alpha[0] < beta[0];
         });

    vector<vector<int>> dp(n + 3, vector<int>(time_limit + 3, 0));
    // dp[i][j]:=i番目(1idx)までの料理の中からj分以内に完食できる美味しさの最大値

    int ans = 0;

    REP(ni, n) {
        REP(ti, time_limit) {
            chmax(dp[ni + 1][ti], dp[ni][ti]);
            int new_t = ti + time_pleasure[ni][0];
            if (new_t <= time_limit) {
                chmax(dp[ni + 1][new_t], dp[ni][ti] + time_pleasure[ni][1]);
            }
        }
        int ni_last = dp[ni][time_limit - 1] + time_pleasure[ni][1];
        chmax(ans, ni_last);
    }
    cout << ans << endl;
}
