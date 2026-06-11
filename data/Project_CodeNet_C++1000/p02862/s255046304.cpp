#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<iostream>
#include <bitset>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
#define vec_unique(_a) _a.erase(std::unique(all(_a)), _a.end());
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
//ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const int mod = 1000000007;
#define COMB_MAX (int)1e6 + 10
ll f[COMB_MAX], rf[COMB_MAX];
ll inv(ll x) {
	ll res = 1;
	ll k = mod - 2;
	ll y = x;
	while (k) {
		if (k & 1) res = (res * y) % mod;
		y = (y * y) % mod;
		k /= 2;
	}
	return res;
}
void init() {
	f[0] = 1;
	rep(i, 1, COMB_MAX) f[i] = (f[i - 1] * i) % mod;
	rep(i, 0, COMB_MAX) rf[i] = inv(f[i]);
}
//---------------------------------------------------------------------------------------------------
ll C(int n, int k) {
	ll a = f[n]; // = n!
	ll b = rf[n - k]; // = (n-k)!
	ll c = rf[k]; // = k!

	ll bc = (b * c) % mod;

	return (a * bc) % mod;
}
int main() {
	ll x, y, k, a, b;
	cin >> x >> y;
	k = (x + y) / 3;
	a = x - k, b = y - k;
	if ((x % 3 + y % 3) % 3 || a < 0 || b < 0) {
		puts("0");
		return 0;
	}
	init();
	printf("%lld\n", C(k, b));
	return 0;
}
