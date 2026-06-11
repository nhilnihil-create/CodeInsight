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

// ========================================================================

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
//1から整数nまでの合計を出す
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
//割り算の%INF対策で逆元を出します

//暇ですね(*'▽')

// ========================================================================

int main() {
	ll x, y; cin >> x >> y;
	ll n, m;
	ll ans = 1;
	ll cnt = 1;
	if ((x + y) % 3 != 0) cout << 0 << endl;
	else {
		m = (x * 2 - y) / 3;
		n = x - 2 * m;
		cnt = n + m;
		if (n < 0 || m < 0) {
			cout << 0 << endl;
		}
		else {
			for (int i = 1; i <= n; i++) {//Nならいけないかな
				ans *= cnt;
				ans %= 1000000007;
				ans *= mg(i, 1000000007);
				ans %= 1000000007;
				cnt--;
			}
			cout << ans << endl;
		}
	}

	return 0;
}