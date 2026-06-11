
#include <cmath>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <functional>
#include <cstdint>
#define fre(i,a) for (auto& i: a)

using namespace std;

using ll = int64_t;
using ld = long double;
using pa = pair<int, int>;

using vi = vector<int>;
using vll = vector<ll>;
using vpa = vector<pa>;

using str = string;
const ll MOD = 1e9+7;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v);
template <typename T, size_t size> ostream &operator<<(ostream &os, const array<T, size> &arr);
template <typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p);
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  string sep;
  for (const auto &x : v)
    os << sep << x, sep = ", ";
  return os << '}';
}
template <typename T, size_t size>
ostream &operator<<(ostream &os, const array<T, size> &arr) {
  os << '{';
  string sep;
  for (const auto &x : arr)
    os << sep << x, sep = ", ";
  return os << '}';
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

ll lmax(ll a, ll b) { return a > b ? a : b; }
ll lmin(ll a, ll b) { return a < b ? a : b; }

ll bpow(ll a, ll b, ll m = MOD) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

vpa pfc(ll N) {
	vpa res;
	for (ll factor = 2; factor * factor <= N; factor++) {
		if (N % factor > 0) continue;
		ll level = 1, cur = 0;
		while (N % factor == 0) {
			N /= factor;
			cur++;
			if (cur == level) {
				/* cout << "levelup" << level << endl; */
				level++;
				cur = 0;
			}
		}
		res.emplace_back(factor, level - 1);
	}
	if (N > 1) {
		res.emplace_back(N, 1);
	}
	return res;
}

void fileio(str p) {
#ifndef FEAST_LOCAL
	freopen((p + ".in").c_str(), "r", stdin);
	freopen((p + ".out").c_str(), "w", stdout);
#endif
}

int tmp, ta, tb;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	/* fileio("problem name"); */
	ll N; cin >> N;
	vpa x = pfc(N);
	ll res = 0;
	/* cout << x << endl; */
	fre(e, x) {
		// n(n+1)/2 = x
		// n^2 + n - 2x = 0
		// n = (-1 +- sqrt(1 + 8x))/2
		/* int n = ((int)(sqrt(8 * e.second + 1)) - 1) / 2; */
		/* cout << n << endl; */
		int n = e.second;
		res += n;
	}
	cout << res << endl;
}
