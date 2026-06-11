#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
 
// ===============================================================
 
using namespace std;
using ll = long long;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using ld = long double;
using ull = unsigned long long;
 
// ===============================================================
 
ll gcd(ll a, ll b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}
//最大公約数
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}
//最小公倍数
ll box(double a) 
{
	ll b = a;
	return b;
}
//切り捨て
ll fff(double a) 
{
	ll b = a + 0.5;
	return b;
}
//四捨五入
ll sum(ll n) { 
	return (1 + n) * n / 2;
}
//1から整数nまでの合計
bool prime(ll a)//素数判定、primeならtrue,違うならfalse
{
	if (a < 2) return false;
	else if (a == 2) return true;
	else if (a % 2 == 0) return false;
	double sqrtNum = sqrt(a);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (a % i == 0)
		{
			return false;
		}
	}
 
	// 素数である
	return true;
}
//素数判定
struct UnionFind {
	vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
 
	UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
		for (int i = 0; i < N; i++) par[i] = i;
	}
 
	int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}
 
	void unite(int x, int y) { // xとyの木を併合
		int rx = root(x); //xの根をrx
		int ry = root(y); //yの根をry
		if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
		par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
	}
 
	bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
}; // // //Unionfind木 // // //Unionfind木
//Unionfind木
 
// ===============================================================
 
int main() {
	ll a, b;
	cin >> a >> b;
	ll ans = 2018;
	for (ll i = a; i <= min(a+4038,b); i++) {
		for (ll j = a; j <= min(a+4038,b); j++) {
			if (i != j) {
				if (i * j % 2019 == 0) {
					ans = 0;
					break;
				}
				if (i * j % 2019 < ans) {
					ans = i * j % 2019;
				}
			}
		}
	}
	cout << ans << endl;
}