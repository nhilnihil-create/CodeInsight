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


int main() {
	ll n, d,a;
	cin >> n >> d >> a;
	vector<pll> ls(n);
	rep(i, 0, n) {
		cin >> ls[i].first >> ls[i].second;
	}
	sort(ls.begin(), ls.end(), kansu);
	vl ruiseki(2*n+5);
	ll ans = 0;
	rep(i, 0, n) {
		ll x = ls[i].first, h = ls[i].second;
		ruiseki[i + 1] += ruiseki[i];
		if (h - ruiseki[i + 1] <= 0)continue;
		ll heru = kiriage((h - ruiseki[i + 1]), a);
		ans += heru;
		ll v = heru * a;
		ruiseki[i + 1] += heru * a;
		ll s = i, t = n;
		ll mid;
		while (t - s > 1) {
			mid = (s + t) / 2;
			if (ls[mid].first > x + 2 * d) {
				t = mid;
			}
			else {
				s = mid;
			}
		}
		ruiseki[t + 1] -= v;
		//print(ruiseki);
	}
	//print(ruiseki);
	printf("%lld\n", ans);
}