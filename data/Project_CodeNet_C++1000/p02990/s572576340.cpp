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
#define vvec vector<vector<ll>>
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
const int mod = 1000000007;
ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }
ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }
ll c(ll n, ll k) { ll a = 1; rep(i, 1, k) { a *= n - i + 1; a /= i; }return a; }
ll mc(ll n, ll m) { ll k = 1, l = 1; rep(i, n - m + 1, n + 1) k = k * i % mod; rep(i, 1, m + 1) l = l * i % mod; l = mpower(l, mod - 2); return k * l % mod; }

#define COMB_MAX (int)2000 + 10
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
	if (k<0 || k>n || n < 0)return 0;
	ll a = f[n]; // = n!
	ll b = rf[n - k]; // = (n-k)!
	ll c = rf[k]; // = k!

	ll bc = (b * c) % mod;

	return (a * bc) % mod;
}
int main() {
	int n, k;
	cin >> n >> k;
	init();
	rep(i, 1, k + 1) {
		ll r = C(n - k + 1, i) * C(k - 1, i - 1);
		printf("%lld\n", r % mod);
	}
	return 0;
}