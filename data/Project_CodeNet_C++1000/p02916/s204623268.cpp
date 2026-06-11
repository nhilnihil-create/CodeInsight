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
using namespace std;
// scanf
#pragma warning(disable: 4996)
// v:vector  type:型  order:greater or less
#define _sort(v,type,order) do { sort(v.begin(),v.end(),order<type>()); } while(0)
// vector 要素の総和算出
// v:vector  default_value:初期値
#define _sum(v,default_value) accumulate(v.begin(),v.end(),default_value )
// vector 最大値( return ite )
#define _max_element(v) max_element(v.begin(),v.end())
// vector 最大値が格納されている要素値
#define _max_element_number(v) distance(v.begin(),max_element(v.begin(),v.end()))
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
// double 引数 x 以上で最小の整数値
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
static int32_t _abs(const int32_t x) { return  (x > 0 ? x : -x); }


int main()
{
	uint32_t n;
	cin >> n;

	vector<uint32_t> a(n);
	vector<uint32_t> b(n);
	vector<uint32_t> c(n);

	for (size_t i = 0; i < a.size(); i++) {
		cin >> a[i];
	}
	for (size_t i = 0; i < b.size(); i++) {
		cin >> b[i];
	}
	for (size_t i = 0; i < c.size()-1; i++) {
		cin >> c[i];
	}

	uint32_t result = 0;
	uint32_t last_a = 21;
	for (uint32_t _a : a) {

		result += b[_a - 1];
		if (_a == last_a + 1) {
			result += c[_a - 2];
		}
		last_a = _a;
	}

	printf("%d\n", result);
	return 0;
}