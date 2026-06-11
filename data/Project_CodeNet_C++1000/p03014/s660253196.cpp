#pragma region header
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
//using系
#pragma region header
using namespace std;
using ll = long long;
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
using kaage = priority_queue<int, vector<int>, greater<int>>;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
constexpr ll mod = 1e9 + 7;
constexpr long double pi = 3.141592653589793238462643383279;
#pragma endregion
// ========================================================================
//define系

//#define int long long
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i <= n; i++)

// ========================================================================

//ライブラリ
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
ll mg(ll a, ll mod) {
	return modpow(a, mod - 2, mod);
}
//割り算の10^9+7等対策で逆元を出します 
ll num(ll a) {
	string s = to_string(a);
	ll sum = 0;
	for (int j = 0; j < s.size(); ++j) {
		sum += s[j] - '0';
	}
	return sum;
}
//整数aのすべての桁の和
#pragma endregion
#pragma endregion


// ========================================================================


#pragma region header
//ある程度のテンプレ(いじって使う)
//これとBFS、あとその時その時で使うものはここに書く
vector<bool> seens;
void dfs(const Graph& G, int v) {
	seens[v] = true; // v を訪問済にする

	// v から行ける各頂点 next_v について
	for (auto next_v : G[v]) {
		if (seens[next_v]) continue; // next_v が探索済だったらスルー
		dfs(G, next_v); // 再帰的に探索
	}
}



// ========================================================================
#pragma endregion

/*signed*/ int main() {
	ll h, w; cin >> h >> w;
	vector<string> a(h);
	for (int i = 0; i < h; i++) cin >> a[i];
	vector<vl> d(h, vl(w));//ひだりからみる
	vector<vl> e(h, vl(w));//右から見る
	vector<vl> f(h, vl(w));//上から見る
	vector<vl> g(h, vl(w));//下から見る
	for (int i = 0; i < h; i++) {//左から
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') d[i][j] = 0;
			else {
				if (j == 0) d[i][j] = 1;
				else d[i][j] = d[i][j - 1] + 1;
			}
		}
	}
	for (int i = 0; i < h; i++) {//右から
		for (int j = w - 1; j >= 0; j--) {
			if (a[i][j] == '#') e[i][j] = 0;
			else {
				if (j == w - 1) e[i][j] = 1;
				else e[i][j] = e[i][j + 1] + 1;
			}
		}
	}
	for (int i = 0; i < h; i++) {//上から
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') f[i][j] = 0;
			else {
				if (i == 0) f[i][j] = 1;
				else f[i][j] = f[i - 1][j] + 1;
			}
		}
	}
	for (int i = h - 1; i >= 0; i--) {//下から
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') g[i][j] = 0;
			else {
				if (i == h - 1) g[i][j] = 1;
				else g[i][j] = g[i + 1][j] + 1;
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			ans = max(ans, d[i][j] + e[i][j] + f[i][j] + g[i][j] - 3);
		}
	}
  cout << ans << endl;

	return 0;
}