//
// Created by hide on 2020/05/15.
//

//参考：http://ehafib.hatenablog.com/entry/2015/12/23/164517
//インクルード(アルファベット順,bits/stdc++.hは使わない派閥)
#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<iterator>//集合演算(積集合,和集合,差集合など)
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

using namespace std;
typedef long long ll;

//マクロ
//forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
//Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはループ変数は1ずつデクリメントされる
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define PRINT(message) cout<<message<<endl //10^5:配列の最大のrange(素数列挙などで使用)

//xにはvectorなどのコンテナ
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
//定数
#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)
//略記
//#define PB push_back //vectorヘの挿入
//#define MP make_pair //pairのコンストラクタ
//#define F first //pairの一つ目の要素
//#define S second //pairの二つ目の要素
int D, G;
int answer = std::numeric_limits<int>::max();
vector<int> p, c;

unordered_map<int, int> mp;

#include <iostream>
#include <vector>
using namespace std;

// 1 つの証言を表す構造体
using pint = pair<int,int>; // 「人」と「0 or 1」

// 入力
int N;
vector<vector<pint>> v;

// 整数 bit に対応する「決め打ち」が整合しているかを判定
bool judge(int bit) {

    // i 人目の証言を検証する
    for (int i = 0; i < N; ++i) {

        // i 人目が「不親切」だったら、証言はすべて無意味
        if ( !(bit & (1 << i)) ) continue;

        // それぞれ確認
        for (pint xy : v[i]) {
            int x = xy.first; // x が
            int y = xy.second; // y = 1: 正直、y = 0: 不親切

            // y = 1 なのに「不親切」だったらダメ
            if (y == 1 && !(bit & (1 << x))) return false;

            // y = 0 なのに「正直者」だったらダメ
            if (y == 0 && (bit & (1 << x))) return false;
        }
    }
    return true;
}


int main() {
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; ++i) {
        int A; cin >> A;
        v[i].resize(A);
        for (int j = 0; j < A; ++j) {
            cin >> v[i][j].first >> v[i][j].second;
            --v[i][j].first; // 0-indexed に
        }
    }

    int res = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {

        // 矛盾 check
        if (judge(bit)) {

            // bit に含まれる人数を数える
            int count = 0;
            for (int i = 0; i < N; ++i) {
                if (bit & (1 << i)) ++count;
            }
            res = max(res, count);
        }
    }

    cout << res << endl;
}