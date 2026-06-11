#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define PP pair<P,P>
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define mkt make_tuple
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;
template<class T> inline void chmax(T& a, T b) { a = max(a, b); }
template<class T> inline void chmin(T& a, T b) { a = min(a, b); }

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return x > 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}
int get_rand(int MIN, int MAX) {
	random_device rnd;
	mt19937_64 mt64(rnd());
	uniform_int_distribution<int>engine(MIN, MAX);
	return engine(mt64);
}
/*--------Library Zone!--------*/

int n;
vector<int>a(222222), b(222222);
int x(int y) {
	return (y + n) % n;
}
int f(vector<int>&v) {
	queue<int>que;
	rep(i, n) {
		if (v[x(i - 1)] + v[x(i + 1)] < v[i]) {
			que.push(i);
		}
	}
	int res = 0;
	while (!que.empty()) {
		int i = que.front(); que.pop();
		if (v[i] % (v[x(i - 1)] + v[x(i + 1)]) == 0) {
			int memo= v[i] / (v[x(i - 1)] + v[x(i + 1)]) - 1;
			res += memo;
			v[i] -= (v[x(i - 1)] + v[x(i + 1)]) * memo;
		}
		else {
			res += v[i] / (v[x(i - 1)] + v[x(i + 1)]);
			v[i] %= v[x(i - 1)] + v[x(i + 1)];
		}
		if (v[x(i - 1)] > v[i] + v[x(i - 2)])que.push(x(i - 1));
		if (v[x(i + 1)] > v[i] + v[x(i + 2)])que.push(x(i + 1));
	}
	return res;
}
signed main() {
	cin >> n;
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> b[i];
	int an1 = f(a), an2 = f(b);
	rep(i, n) {
		if (a[i] != b[i]) {
			cout << -1 << endl; return 0;
		}
	}
	cout << an2 - an1 << endl;
}
