#include <cmath>
#include <cstdio>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <functional>
#include <chrono>
using namespace std;

#define rep(i,s,n) for(ll i=s;i<(n);++i)
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = (1LL << 60);
//constexpr ll MOD = (1e9 + 7);
constexpr ll MOD = (998244353);

using vl = vector<ll>;
using vvl = vector<vector<ll>>;

template<class T>
vector<vector<T>> vvt(T init, ll m, ll n) {
	vector<vector<T>> ans = vector<vector<T>>(m, vector<T>(n, init));
	return move(ans);
}

template<class T>
vector<T> vt(T init,ll n) {
	vector<T> ans = vector<T>(n, init);
	return move(ans);
}

template<class T>
T maxVec(vector<T> &v) {
	T ans = -INF;
	rep(i,0, v.size()) {
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
void print(const C& c, std::ostream& os = std::cout)
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

bool kansu(pll a, pll b) {
	return a.first < b.first;
}

ll kiriage(ll a, ll b) {
	if (a % b == 0)return a / b;
	return a / b + 1;
}

ll n,m,x,y;
vl a, b;

ll modpow(ll n, ll a, ll m) {
	if (a == 0)return 1;
	if (a % 2 == 0) {
		ll b = modpow(n, a / 2, m);
		return (b * b) % m;
	}
	else if (a % 2 == 1) return (n * modpow(n, a - 1, m)) % m;
}

int main() {
	cin >> n;
	vl d(n), count(n+5);
	ll max_val = 0;
	rep(i, 0, n) {
		cin >> d[i];
		count[d[i]] ++;
		max_val = max(max_val, d[i]);
		if (i != 0 && d[i] == 0) {
			printf("0\n");
			exit(0);
		}
	}
	ll ans = count[0];
	rep(i, 1, max_val + 1) {
		ll c = modpow(count[i - 1], count[i], MOD);
		ans %= MOD;
		c %= MOD;
		ans *= c;
		ans %= MOD;
	}
	printf("%lld\n", ans % MOD);
}