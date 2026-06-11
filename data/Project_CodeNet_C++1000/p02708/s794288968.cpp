#include <cmath>
#include <cstdio>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <stdio.h>
#include <functional>
#include <chrono>
#include <boost/version.hpp>
using namespace std;

#define rep(i,s,n) for(ll i=s;i<(n);++i)
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = (1LL << 60);
constexpr ll MAX_INF = 9223372036854775807;
constexpr ll MOD = (1e9 + 7);
//constexpr ll MOD = (998244353);

using vl = vector<ll>;
using vvl = vector<vector<ll>>;

template<class T>
vector<vector<T>> vvt(T init, ll m, ll n) {
	vector<vector<T>> ans = vector<vector<T>>(m, vector<T>(n, init));
	return move(ans);
}

template<class T>
vector<T> vt(T init, ll n) {
	vector<T> ans = vector<T>(n, init);
	return move(ans);
}

template<class T>
T maxVec(vector<T>& v) {
	T ans = -INF;
	rep(i, 0, v.size()) {
		ans = max(ans, v[i]);
	}
	return ans;
}

// 素数判定
bool judge(ll n) {
	for (ll i = 2; i * i <= n; i++) if (n %= i)return false;
	return true;
}


template <class C>
void print(const C & c, std::ostream & os = std::cout)
{
	std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, ", "));
	os << std::endl;
}
/*
ll count(ll n,ll r) {
	ll ans = 0,check = 1;
	rep(i,0, r) {
		if ((n & check) > 0) {
			ans++;
		}
		check = check << 1;
	}
	return ans;
}
*/
bool sortreverse(ll a, ll b) {
	return a > b;
}


ll kiriage(ll a, ll b) {
	if (a % b == 0)return a / b;
	return a / b + 1;
}

ll n, m, t, q, s,k,h,w,x,y;

void warshall_floyd(ll v_num,vector<vector<long long>> &d) {
	for (long long k = 0; k < v_num; k++) {       // 経由する頂点
		for (long long i = 0; i < v_num; i++) {    // 始点
			for (long long j = 0; j < v_num; j++) {  // 終点
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

ll modpow(ll n, ll a, ll m) {
	if (n > 1000000000) {
		printf("large");
		exit(0);
	}
	if (a == 0)return 1;
	if (a % 2 == 0) {
		ll b = modpow(n, a / 2, m);
		if (b*b > 1000000000) {
			printf("large");
			exit(0);
		}
		
		return (b * b);
	}
	else if (a % 2 == 1) {
		ll b = modpow(n, a -1, m);
		if (b*n > 1000000000) {
			printf("large");
			exit(0);
		}
		return (n * b);
	}
}

long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}


int main() {
	// ↓この２行が追加部分
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	ll f;
	cin >> n >> k;

	ll ans = 0;
	rep(i, k, n+2) {
		//ans += (((kaijyo[n + 1] * kaijyoINV[i])%MOD) * kaijyoINV[n+1-i]) %MOD;
		//ans %= MOD;
		ll minNum = (i - 1) * i / 2, maxNum = (n + 1) * n / 2 - (n + 1 - i) * (n - i) / 2;
		ans += (maxNum - minNum + 1) % MOD;
		ans %= MOD;
	}
	printf("%lld\n", ans);
}