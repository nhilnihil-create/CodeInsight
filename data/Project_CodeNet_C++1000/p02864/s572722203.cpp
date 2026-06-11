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
typedef long long ll;
typedef long double ld;
#define all(a) (a).begin(),(a).end()
#define EPS (1e-5)
#define bit(n,k) ((n>>k)&1)
const ll Mod = 1000000007;
const ll mod = 998244353;
struct H {
	ll x, y;
	bool operator<(const H& b) const {
		if (x != b.x) return x < b.x;
		return y < b.y;
	}
	bool operator>(const H& b) const {
		if (x != b.x) return x > b.x;
		return y > b.y;
	}
	bool operator==(const H& b) const { return x == b.x && y == b.y; }
	bool operator!=(const H& b) const { return (*this) != b; }
};
struct P {
	ll pos, cost;
	bool operator<(const P& b) const { return cost < b.cost; }
	bool operator>(const P& b) const { return cost > b.cost; }
};
struct B {
	ll to, cost;
};
struct E {
	ll from, to, cost;
	bool operator<(const E& b) const { return cost < b.cost; }
	bool operator>(const E& b) const { return cost > b.cost; }
};
template<typename T, typename U>
void chmin(T& a, U b) {
	if (a > b) a = b;
}
template<typename T, typename U>
void chmax(T& a, U b) {
	if (a < b) a = b;
}
template<typename T>
T max_0(T a) {
	if (a < 0) return 0;
	return a;
}
template<typename T>
T min_0(T a) {
	if (a > 0) return 0;
	return a;
}
ll read() {
	ll u;
	ll k = scanf("%lld", &u);
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
}//x^n%p
ll bitcount(ll x) {
	int sum = 0;
	for (int i = 0; i < 20; i++)
		if ((1ll << i) & x) sum++;
	return sum;
}
ll fact_[5000000];
ll comb(ll x, ll y, ll mod = Mod) {
	if (!fact_[0]) {
		fact_[0] = 1;
		for (int i = 1; i < 5000000; i++) {
			fact_[i] = fact_[i - 1] * i % mod;
		}
	}
	if (x < y) return 0;
	return mod_pow(fact_[x], mod, mod) *
		mod_pow(fact_[x - y], mod - 2, mod) % mod *
		mod_pow(fact_[y], mod - 2, mod) % mod;
}//xCy
const ll Inf = 3023372036854775807;
const int inf = 1500000000;
#define int long long
//----------------------------------------------------
int n, k, h[400];
int dp[400][400];
//i番目まででj個消費された時の最小コスト
signed main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	n++;
	for (int i = 0; i < 400; i++) {
		for (int j = 0; j < 400; j++) {
			dp[i][j] = Inf;
		}
	}
	dp[0][0] = 0;
	dp[0][1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int z = 0; z < i; z++) {
				dp[i][j] = min(dp[i][j], dp[z][j - 1] + max(0ll, h[i] - h[z]));
			}
		}
	}
	int ans = Inf;
	for (int i = 0; i < n; i++) {
		ans = min(ans, dp[i][n - k]);
	}
	cout << ans << endl;
}