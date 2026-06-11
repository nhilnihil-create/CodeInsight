//include,using,define等
#pragma region header
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
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
//using系
#pragma region header
using namespace std;
using ll = long long;
using lint = long long;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using vvi = vector<vector<int>>;
using Graph = vvi;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using ld = long double;
using ull = unsigned long long;
using ui = unsigned int;
using qul = queue<ll>;
using pql = priority_queue<ll>;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
constexpr ll mod = 1e9 + 7;
constexpr long double pi = 3.141592653589793238462643383279;
#pragma endregion
// ========================================================================
//define
#pragma region header
//#define int long long
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i <= n; i++)
#define inf (ll)(3e18)
#define P pair<int,int>
template <class T>
bool chmax(T & a, const T & b) {
	if (a < b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}
template <class T>
bool chmin(T& a, const T& b) {
	if (a > b) {
		a = b;  // aをbで更新
		return true;
	}
	return false;
}
#pragma endregion
#pragma endregion
//整数系ライブラリ
#pragma region header
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
ll mch(ll n) {
	if (n == 1) return 1;
	else return n * mch(n - 1);
}
//1から整数nまでの階乗を出す(INFで割っていない)
bool prime(ll a)//素数判定、primeならtrue,違うならfalse
{
	if (a < 2) return false;
	else if (a == 2) return true;
	else if (a % 2 == 0) return false;
	double m = sqrt(a);
	for (int i = 3; i <= m; i += 2)
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
ll modpow(ll a, ll n, ll mod) {
	ll hi = 1;
	while (n > 0) {
		if (n & 1) hi = hi * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return hi;
}
//いろいろやります（ただの前座）
ll modinv(ll a, ll mod) {
	return modpow(a, mod - 2, mod);
}
//割り算の10^9+7等対策で逆元を出します 
ll num(ll a) {
	string s = to_string(a);
	ll sum = 0;
	for (int j = 0; j < s.size(); ++j) {
		sum += (ll)s[j] - '0';
	}
	return sum;
}
//整数aのすべての桁の和
#pragma endregion
//グラフ・木系ライブラリ
#pragma region header
struct UnionFind {
	vector<int> par;

	UnionFind(int n) : par(n, -1) { }
	void init(int n) { par.assign(n, -1); }

	int root(int x) {//根を出す
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool same(int x, int y) {//同じ集合なのかを調べる
		return root(x) == root(y);
	}

	bool unite(int x, int y) {//xの根とyの根をつなげる
		x = root(x); y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x) {
		return -par[root(x)];
	}
};

// ========================================================================
#pragma endregion
//ここから問題ごとに書く
bool dp[30010][5][10010] = { false };


/*signed*/int main() {
	dp[0][0][0] = true;
	lint n; cin >> n;
	string s; cin >> s;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 3; j++) {
			for (int k = 0; k <= 1000; k++) {
				if (!(dp[i][j][k])) continue;
				dp[i + 1][j][k] = true;
				if (j < 3) dp[i + 1][j + 1][k * 10 + (s[i] - '0')] = true;
			}
		}
	}
	lint ans = 0;
	for (int i = 0; i < 1000; i++) {
		if (dp[n][3][i]) ans++;
	}
	cout << ans << endl;

	return 0;
}