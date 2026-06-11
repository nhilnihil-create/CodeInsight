/**
*	created: 11.08.2020 17:34:57
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // 競プロにおいて，bit演算の話が出てくるのは大概"bit全探索"のときになります
    // bit全探索というのは，合計2^n通りの場合を全て調べるときに使われます．
    // この問題では，2^H * 2^W 通りの塗り方がありますが，1 <= H,W <= 6 という制約を考えると，
    // その全てをチェックしても制限時間に間に合うので，bit全探索をします．

    // 入力
    int h, w, k; cin >> h >> w >> k;
    char mp[h][w]; // charを要素に持つ二次元配列(vectorとは違って可変長ではない)の宣言
    rep(i,h) rep(j,w) cin >> mp[i][j]; // 入力
    int ans = 0;
    // 各々の塗り方について，黒いマスがいくつ残っているかを調べたい
    // 2重ループで計2^H * 2^W 通りを調べる
    // bit1は行の情報，bit2は列の情報を保持していると考えます．
    rep(bit1,(1<<h)) rep(bit2,(1<<w)) {
        int cnt = 0; // 黒いマスの個数を保持する変数
        // 2重ループで，黒いマスがいくつあるかを調べる
        rep(i,h) rep(j,w) {
            // いま，i行目j列目のマスを見ています．
            // ここで，bit1, bit2を二進数表記にして見たとき，
            // "右から"i,j番目が1であるならば，i行目とj列目は赤く塗られていると考える．
            // では，その判定をどのように行うか
            // 一つ目のアイデアとしては，bit1とbit2を二進数に変換する関数を考えて
            // それを更にstringに変換し各桁が0か1かチェックをする
            // →面倒臭い
            // ここでbitシフト&演算の出番！
            // bit演算において，足りない部分のbitは0で埋められることに注意すると
            // bit1,bit2を"右に"i,jだけシフトして，1とAND演算を行うことを考える
            // 結果が1の時，bit1,bit2の"右から"i,j番目は赤く塗られていると判定すればよい
            // ここで，bit1,bit2を"右から眺める"ということが必要になる
            // これは10進数で"n桁目"を考える時と逆なので，若干直感に反します．
            // c++では1はtrueと同義であることに注意して
            if ((bit1 >> i) & 1) continue; // i行目が塗られている時はスルー
            else if ((bit2 >> j) & 1) continue; // j行目が塗られている時もスルー
            else if (mp[i][j] == '#') cnt++; // 赤色に塗られていなくて，黒色のマスだったらカウント
        }
            if (cnt == k) ans++; //カウントした結果がkと等しかったら，答えを+1
        
    }
    cout << ans << endl; // 出力して終了
    return 0;
}