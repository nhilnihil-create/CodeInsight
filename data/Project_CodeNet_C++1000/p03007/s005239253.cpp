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

ll n, m, x, y, t, q, s,k;

int main() {
	cin >> n;
	vl a(n);
	rep(i, 0, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vl puras, minas;
	rep(i, 0, n) {
		if (a[i] < 0) {
			minas.push_back(a[i]);
		}
		else {
			puras.push_back(a[i]);
		}
	}
	if (puras.size() == 0) {
		ll tmp = minas.back();
		minas.pop_back();
		puras.push_back(tmp);
	}
	else if (minas.size() == 0) {
		swap(puras.back(), puras.front());
		ll tmp = puras.back();
		puras.pop_back();
		minas.push_back(tmp);
	}
	ll M = 0;
	rep(i, 0, puras.size()) {
		M += puras[i];
	}
	rep(i, 0, minas.size()) {
		M -= minas[i];
	}
	printf("%lld\n", M);
	ll ref = minas.back();
	minas.pop_back();
	ll tmp = puras.size() - 1;
	rep(i, 0, tmp) {
		printf("%lld %lld\n", ref, puras.back());
		ref -= puras.back();
		puras.pop_back();
	}
	printf("%lld %lld\n", puras.back(), ref);
	ref = puras.back() - ref;
	tmp = minas.size();
	rep(i, 0, tmp) {
		printf("%lld %lld\n", ref, minas.back());
		ref -= minas.back();
		minas.pop_back();
	}
}