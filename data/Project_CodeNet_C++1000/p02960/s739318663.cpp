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
#define rep2(i, a)for(auto i : a)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x, std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
#define vec_unique(_a) _a.erase(std::unique(all(_a)), _a.end());
#define vvec vector<vector<ll>>
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const int mod = 1000000007;
ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }
ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }
ll co(ll n, ll k) { ll a = 1; rep(i, 1, k) { a *= n - i + 1; a /= i; }return a; }
ll mc(ll n, ll m) { ll k = 1, l = 1; rep(i, n - m + 1, n + 1) k = k * i % mod; rep(i, 1, m + 1) l = l * i % mod; l = mpower(l, mod - 2); return k * l % mod; }
typedef struct { int g, c, p; } j;
int main()
{
	string s;
	cin >> s;
	reverse(all(s));
	ll k = 1ll, r = 0;
	vector<ll> t;
	const ll M = 13;
	rep2(c, s) {
		if (c != '?')r += (c - '0') * k, r %= M;
		else t.push_back(k);
		k *= 10ll;
		k %= M;
	}
	vector<vector<ll>> dp(t.size() + 1, vector<ll>(13));
	dp[0][r]++;
	rep(i, 1, t.size() + 1) {
		rep(i2, 0, 13) {
			rep(i3, 0, 10) {
				dp[i][(i2 + t[i-1]*i3) % 13] += dp[i - 1][i2];
				dp[i][(i2 + t[i - 1] * i3) % 13] %= mod;
			}
		}
	}
	printf("%lld\n", dp[t.size()][5]);
	return 0;
}