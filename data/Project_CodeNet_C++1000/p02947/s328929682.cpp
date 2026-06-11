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

// double result = 0;
// printf("%.12f\n", result);

// v:vector  type:型  order:greater(大きい順) or less(小さい順)
#define _sort(v,type,order) do { sort(v.begin(),v.end(),order<type>()); } while(0)
/*
	◆pairでもソートは可能

	vector<pair<int32_t, int32_t>> pr(n);
	sort(pr.begin(), pr.end(),_compare);

	bool _compare(pair<int32_t, int32_t> a, pair<int32_t, int32_t> b)
	{

	#if 0	// first での sort

	#if 0
		// 昇順
		if (a.first != b.first) {
			return a.first < b.first;
		}
		// secondが同じならfirstでソート
		return a.second < b.second;
	#else
		// 降順
		if (a.first != b.first) {
			return a.first > b.first;
		}
		// secondが同じならfirstでソート
		return a.second > b.second;
	#endif

	#else	// second での sort

	#if 1
		// 昇順
		if (a.second != b.second) {
			return a.second < b.second;
		}
		// secondが同じならfirstでソート
		return a.first < b.first;
	#else
		// 降順
		if (a.second != b.second) {
			return a.second > b.second;
		}
		// secondが同じならfirstでソート
		return a.first > b.first;
	#endif

	#endif

	}

*/

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
//                                                              member.emplace(2)とかも同じ member.size()で確認すると同じ値の挿入ではサイズ変化はない
//multiset<uint32_t> v;	// 重複するデータも保持する事はできる   member.insert(2) member.insert(2) ⇒ member.count(2)は2

// 丸め
#define _round(v) round(v)
// 2乗 / 3乗
#define _square(v) pow(v,2)
#define _cube(v)   pow(v,3)
// 大小判定
#define _max(x,y) max(x,y)
#define _min(x,y) min(x,y)
template <class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template <class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

// string ⇒ int
#define _stringtoi(s) stoi(s)
// double 平方根
#define _sqrt(x) sqrt(x)
// double 引数 x 以上で最小の整数値 ex) 3.30303 ⇒ 4
#define _ceil(x) ceil(x)
// 指定された要素 【以上の】　　値が現れる最初の位置のイテレータを取得する
#define _lower_bound(v,min) lower_bound(v.begin(), v.end(), min)
// 指定された要素 【より大きい】値が現れる最初の位置のイテレータを取得する
#define _upper_bound(v,min) upper_bound(v.begin(), v.end(), min)

// 順列 n個の数が与えられる
// 0,1,2,...,n-1
// 全ての並べ方を1行ごとに出力する
// ex 0 1 2 / 0 2 1 / 1 0 2 / 1 2 0 / 2 0 1 / 2 1 0
#define _next_permutation(v) do {     \
	for (auto num : v) {              \
		printf("%d ", num);           \
	}                                 \
	printf("\n");                     \
	/* ※ 昇順である必要がある     */ \
	/* ※ pair も pair.firstで可能 */ \
} while (next_permutation(v.begin(), v.end()))

// ■bitset
// 100 桁の 2 進数を定義する。
// bitset<100> bs;
// 
// 8桁 の 2進数を定義し、10進数 131で初期化
// bitset<8> bs(131);			// 7 ビット目から 0 ビット目への順番で、10000011 になる
// 
// 8桁 の 2進数を定義し、2進数で初期化
// bitset<8> bs("10000011");	// 7 ビット目から 0 ビット目への順番で、10000011 となる。
// string _bs; cin >> _bs; bitset<100> bs(_bs); _bs = "10000011"であれば上記と同様
// 
// 与えられる数値について、それぞれの和を算出する場合
// 下記コードでビットが立っている要素値＝和の値となる
// ex.) AGC 020 C https://atcoder.jp/contests/agc020/tasks/agc020_c
// bitset<1000> dp;
// p[0] = 1;
// for (int i = 0; i < N; ++i) {
//    dp |= (dp << A[i]);
// }

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
//
// 2次元 vector の初期化
// vector< vector<int> >  s( n, vector<int>(m, 0) );

// pair
// vector<vector<pair<int32_t,int32_t>>> f(n);
// ⇒ 挿入 f[i].push_back(make_pair(x, y));

// Union Find Tree

class UnionFind
{
public:
	vector <int32_t> par; // 各元の親を表す配列
	vector <int32_t> siz; // 素集合のサイズを表す配列(1 で初期化)

	// Constructor 初期では親は自分自身
	UnionFind(int32_t sz_) : par(sz_), siz(sz_, 1LL) { for (int32_t i = 0; i < sz_; ++i) par[i] = i; }

	void init(int32_t sz_)
	{
		par.resize(sz_);
		siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
		for (int32_t i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
	}

	// Find
	int32_t root(int32_t x)
	{
		// x の親の親を x の親とする
		while (par[x] != x) {
			x = par[x] = par[par[x]];
			//			printf("%d\n", x);
		}
		return x;
	}

	// Union(Unite, Merge)
	bool merge(int32_t x, int32_t y)
	{
		x = root(x);
		y = root(y);
		if (x == y) return false;
		// merge technique（データ構造をマージするテク．小を大にくっつける）
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}

	// 連結判定
	bool is_same(int32_t x, int32_t y) { return root(x) == root(y); }

	// 素集合のサイズ
	int32_t size(int32_t x) { return siz[root(x)]; }

	// 参照
	void view(void) {
		for (size_t i = 0; i < par.size(); i++) {
			printf("%d\n", par[i]);
		}
	}

};

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

/*************************************************************/
// ABC 137
// C - Green Bin
// https://atcoder.jp/contests/abc137/tasks/abc137_c
/*
	■問題文
	文字列 a に含まれる文字を何らかの順序で並べることで得られる文字列を a の アナグラム と呼びます。
	例えば、greenbin は beginner のアナグラムです。
	このように、同じ文字が複数回現れるときはその文字をちょうどその回数だけ使わなければなりません。
	N 個の文字列 s1,s2,…,sN が与えられます。
	それぞれの文字列は長さが 10 で英小文字からなり、またこれらの文字列はすべて異なります。
	二つの整数 i,j (1≤i<j≤N) の組であって、si が sj のアナグラムであるようなものの個数を求めてください。

	■制約
	・2 ≤ N ≤ 1e5
	・si は長さ 10 の文字列である。
	・si の各文字は英小文字である。
	・s1,s2,…,sN はすべて異なる。

	■入力
	N
	s1
	s2
	:
	sN
	
	■出力
	二つの整数 i,j (1 ≤ i < j ≤ N) の組であって、si が sj のアナグラムであるようなものの個数を出力せよ。

	■入力例
	3
	acornistnt
	peanutbomb
	constraint

	■出力例
	1

	s1= acornistnt は s3= constraint のアナグラムです。他に si が sj のアナグラムであるような i,j の組はないため、答えは 1 です。
*/

int main()
{
	int32_t n;
	cin >> n;

	vector<map<char, int32_t>> v(n);
	for (int32_t i = 0; i < n; i++) {
		map<char, int32_t> mp;
		string str;
		cin >> str;
		for (int32_t j = 0; j < 10; j++) {
			mp[str[j]]++;
		}
		v[i] = mp;
	}

	sort(v.begin(), v.end());

	int64_t result = 0;
	int64_t temp;
	for (int64_t i = 0; i < n - 1; i++) {
		temp = 0;
		for (int64_t j = i + 1; j < n; j++) {
			if (v[i] != v[j]) { break; }
			temp++;
		}
		for (int64_t j = 1; j <= temp; j++) {
			result += j;
		}
		i += temp;
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
