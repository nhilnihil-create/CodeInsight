#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<cstring>
#include<bitset>
#include<unordered_map>
#include<climits>
#include<fstream>
#include<time.h>
#include<cassert>

using namespace std;
#define ll long long
#define ld long double
#define int long long
#define all(a) (a).begin(),(a).end()
#define EPS (1e-13)
#define fs first
#define sc second
#define xx first
#define yy second.first
#define zz second.second
#define H pair<int, int>
#define P pair<int, pair<int, int>>
#define Q(i,j,k) mkp(i,mkp(j,k))
#define rep(i,n) for(int (i) = 0 ; (i) < (n) ; (i)++)
#define mkp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define crdcomp(b) sort(all((b)));(b).erase(unique(all((b))),(b).end())
const int mod = 1e9 + 7;
const int Mod = 998244353;
const ll Inf = 3 * 1e18;
const int inf = 15 * 1e8;
ll read() {
	ll u, k = scanf("%lld", &u);
	return u;
}
ll gcd(ll i, ll j) {
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcd(j % i, i);
}
ll mod_pow(ll x, ll n, ll p) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % p;
		x = x * x % p;
		n >>= 1;
	}
	return res;
}
ll bcount(ll x) {
	int sum = 0;
	for (int i = 0; i < 20; i++)
		if ((1ll << i) & x) sum++;
	return sum;
}
const int fn_ = 2000000;
ll fact_[fn_], comp_[fn_];
ll comb(ll x, ll y, ll Mod = mod) {
	if (!fact_[0]) {
		fact_[0] = 1; comp_[0] = 1;
		for (int i = 1; i < fn_; i++) {
			fact_[i] = fact_[i - 1] * i % Mod;
			comp_[i] = mod_pow(fact_[i], Mod - 2, Mod);
		}
	}
	if (x < y) return 0;
	return fact_[x] * comp_[x - y] % Mod * comp_[y] % Mod;
}
//---------------------------------------------------

signed main() {
	int n;
	cin >> n;
	vector<int>a(n);
	rep(i, n)cin >> a[i];
	int s = 0;
	rep(i, n)s ^= a[i];
	int ans = s;
	rep(i, n)a[i] &= ~s;
	int r = 0;
	vector<int>top(n);
	for (int i = 60; i >= 0; i--) {
		int j = r;
		for (; j < n; j++) {
			if (a[j] >> i & 1) {
				swap(a[r], a[j]);
				break;
			}
		}
		if (j == n) continue;
		top[r] = i;
		rep(k, n) {
			if (r == k) continue;
			if (a[k] >> i & 1) a[k] ^= a[r];
		}
		r++;
	}
	int x = 0;
	for (int i = 60; i >= 0; i--) {
		int nx = x | (1ll << i);
		int b = nx;
		rep(j, r) {
			if (b >> top[j] & 1) b ^= a[j];
		}
		if ((b & nx) == 0) x = nx;
	}
	ans += x * 2;
	cout << ans << endl;
}