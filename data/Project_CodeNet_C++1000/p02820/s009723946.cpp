// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <map>
#include <numeric>
#include <set>
#include <queue>
#include <bitset>
using namespace std;

#define ll long long
#define ld long double
#define pi 3.14159265359;
// %llu %lf

// v:vector  type:型  order:greater(大きい順) or less(小さい順)
#define _sort(v,type,order) do { sort(v.begin(),v.end(),order<type>()); } while(0)
// vector 要素の総和算出
// v:vector  default_value:初期値
#define _sum(v,default_value) accumulate(v.begin(),v.end(),default_value )
// vector 最大値( return ite )
#define _max_element(v) max_element(v.begin(),v.end())
// vector 最小値( return ite )
#define _min_element(v) min_element(v.begin(),v.end())
// vector 最大値が格納されている要素値
#define _max_element_number(v) distance(v.begin(),max_element(v.begin(),v.end()))
// 特定コンテナの中から特定の値をカウントする
#define _count(v,value) count(v.begin(),v.end(),value)

//set<uint32_t> member;	// 重複するデータを保持する事はできない member.insert(2) member.insert(2) ⇒ member.count(2)は1
//                                                              member.emplace(2)とかも同じ
//multiset<uint32_t> v;	// 重複するデータも保持する事はできる   member.insert(2) member.insert(2) ⇒ member.count(2)は2

// 丸め
#define _round(v) round(v)
// 2乗 / 3乗
#define _square(v) pow(v,2)
#define _cube(v)   pow(v,3)
// 大小判定
#define _max(x,y) max(x,y)
#define _min(x,y) min(x,y)
// string ⇒ int
#define _stringtoi(s) stoi(s)
// double 平方根
#define _sqrt(x) sqrt(x)
// double 引数 x 以上で最小の整数値 ex) 3.30303 ⇒ 4
#define _ceil(x) ceil(x)
// 指定された要素以上の値が現れる最初の位置のイテレータを取得する
#define _lower_bound(v,min) lower_bound(v.begin(), v.end(), min)
// 指定された要素より大きい値が現れる最初の位置のイテレータを取得する
#define _upper_bound(v,min) upper_bound(v.begin(), v.end(), min)

// 順列 n個の数が与えられる
// 0,1,2,...,n-1
// 全ての並べ方を1行ごとに出力する
// ex 0 1 2 / 0 2 1 / 1 0 2 / 1 2 0 / 2 0 1 / 2 1 0
#define _next_permutation(v) do {   \
	for (auto num : v) {            \
		printf("%d ", num);         \
	}                               \
	printf("\n");                   \
} while (next_permutation(v.begin(), v.end()))

// 絶対値
template<typename T>
static T _abs(const T x) { return  (x > 0 ? x : -x); }

// 最大公約数
int64_t gcd(int64_t a, int64_t b) { while (b) { int64_t c = b; b = a % b; a = c; } return a; }
// 最小公倍数
int64_t lcm(int64_t a, int64_t b) { if (!a || !b) return 0; return a * b / gcd(a, b); }

// 多次元 std::vector 生成
template<class T>
vector<T> make_vec(size_t a) { return vector<T>(a); }
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts) { return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...)); }
// ex) auto dp = make_vec<uint64_t>(SIZE + 1, 2, 2);

// ■
// UINT32_MAX
// 4294967295 ≒ 4 * 1e9

// ■
// 割り算した結果との比較での丸め対処時 
// ABC 161 B
// https://atcoder.jp/contests/abc161/tasks/abc161_b
// double   border = _sum(v, 0 / (double)(4 * m);
//            ↓
// uint32_t border = (_sum(v, 0) + (4 * m) - 1) / (4 * m);

// ■
// N の数が与えられた場合の組合せ N * (N - 1) / 2


/*************************************************************/
// ARC 149
// D - Prediction and Restriction
// https://atcoder.jp/contests/abc149/tasks/abc149_d
/*
	■問題文
	高橋君は、ゲームセンターで「じゃんけんバトル」というゲームをプレイすることにしました。このゲームのルールは以下の通りです。

    プレイヤーは筐体と N 回じゃんけんを行う (あいこの場合も 1 回のジャンケンと数える)。
	プレイヤーがじゃんけんで勝った場合、プレイヤーは出した手に応じて以下のスコアを得る (あいこや負けは 0 点)。

    グーで勝った場合	R 点
	チョキで勝った場合	S 点
	パーで勝った場合	P 点

	ただし、ちょうど K 回前のじゃんけんで出した手と同じ手を出すことはできない。( K 回目までのじゃんけんでは好きな手を出せる。)
	筐体は、各回のジャンケンで出す手をゲーム開始前に決定します。能力者である高橋君は、ゲーム開始前にこれをすべて読み取りました。
	高橋君が読み取った情報は文字列 T として与えられます。T の i(1≤i≤N) 文字目が r のときは i 回目のじゃんけんで筐体がグーを出すことを、s のときはチョキを出すことを、p のときはパーを出すことを表します。
	高橋君が N 回のじゃんけんで出す手を最適に選んだとき、ゲーム終了までに最大で合計何点を得られるでしょうか。

	■制約
	-

	■入力
	N K
	R S P
	T

	■入力例
	5 2
	8 7 6
	rsrpr
	
	■出力例
	27

	筐体は、{グー、チョキ、グー、パー、グー} と手を出します。
	これに対して、例えば {パー、グー、グー、チョキ、パー} と出せば、27 点を獲得できます。 これより大きい点は獲得できないので、27 を出力します。

*/

int main()
{
	int32_t n, k, r, s, p;
	string t;

	cin >> n >> k >> r >> s >> p;
	cin >> t;

	int32_t result = 0;
	vector<int32_t> v(n);

	// p q r s 
	int32_t point[4] = { s,0,p,r };

	for (int32_t i = 0; i < n; i++) {

		// p パー
		// r グー
		// s チョキ
		v[i] = t[i] - 'p';

//		printf("%d\n", v[i]);

		if (i >= k) {
			if (v[i - k] == v[i]) {
				v[i] = 4;
				continue;
			}
		}
		result += point[v[i]];
	}

	cout << result << endl;
	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
