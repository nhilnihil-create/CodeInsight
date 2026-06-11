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
#define INF 1 << 30
const int mod = 1000000007;
ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }
ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }
ll ac(ll n, ll k) { ll a = 1; rep(i, 1, k) { a *= n - i + 1; a /= i; }return a; }
ll mc(ll n, ll m) { ll k = 1, l = 1; rep(i, n - m + 1, n + 1) k = k * i % mod; rep(i, 1, m + 1) l = l * i % mod; l = mpower(l, mod - 2); return k * l % mod; }
vector<int> ans, f;
set<int> k;
vector<vector<int>> G;
void dfs(int v) {
	ans.push_back(v);
	for (auto n : G[v]) {
		if (f[n] == 0) {
			f[n] = 1;
			k.insert(n);
		}
	}
	if (k.size()) {
		int nv = *k.begin();
		k.erase(*k.begin());
		dfs(nv);
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, 0, n)cin >> a[i];
	sort(all(a));
	rep(i, 0, n)b[i] = a[i];
	int k;
	auto it = lower_bound(all(a), 0);
	if (it == a.end()) {
		it = a.end() - 1;
	}
	k = it - a.begin();
	if (k == 0)k++;
	rep(i, k, n - 1) {
		b[0] -= b[i];
	}
	rep(i, 1, k) {
		b[n - 1] -= b[i];
	}
	printf("%d\n", b[n - 1] - b[0]);
	rep(i, k, n - 1){
		printf("%d %d\n", a[0], a[i]);
		a[0] -= a[i];
	}
	rep(i, 1, k) {
		printf("%d %d\n", a[n - 1], a[i]);
		a[n - 1] -= a[i];
	}
	printf("%d %d\n", a[n - 1], a[0]);
	return 0;
}
