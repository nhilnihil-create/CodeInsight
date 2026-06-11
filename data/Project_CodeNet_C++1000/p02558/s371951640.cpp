#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

#include <atcoder/all>

using namespace atcoder;
using namespace std;
using lint = long long;
using P = pair<lint, lint>;

#define rep(i, n) for (lint i = 0; i < (n); ++i)
#define rep1(i, n) for (lint i = 1; i < (n); ++i)
#define repn(i, a, b) for(lint i = (a); i < (b); ++i)
#define rep_inv(i, n) for (lint i = (n); i >= 0; --i)
#define rep_inv1(i, n) for(lint i = (n); i >= 1; --i)
#define all(vec) (vec).begin(), (vec).end()
#define cend printf("\n")

constexpr lint Mod = /**/ 1000'000'007LL /*/ 998'244'353LL /**/;
constexpr lint Inf = 4'500'000'000'000'000'007LL; //4.5e18+7
constexpr double Pi = 3.141592653589793;

template<class T> using prique     = priority_queue<T>;
template<class T> using prique_inv = priority_queue<T, vector<T>, greater<T>>;
template<class T> inline bool chmin(T& a, const T& b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, const T& b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline istream& operator>>(istream& is, vector<T>& v) { for (auto& e : v) is >> e; return is; }
template<class T> inline ostream& operator<<(ostream& os, const vector<T>& v) {
	size_t i = 0, n = v.size();
	for (const auto& e : v) {
		os << e;
		if (i + 1 < n) os << " ";
		++i;
	}
	return os;
}
template<class T, class U> inline istream& operator>>(istream& is, pair<T, U>& rhs) { return is >> rhs.first >> rhs.second; }
template<class T, class U> inline ostream& operator<<(ostream& os, const pair<T, U>& rhs) { return os << "{" << rhs.first << ", " << rhs.second << "}"; }
template<class T, class U> inline void print(const T& a, const U& b, bool f) {
	if (f) cout << a << "\n";
	else cout << b << "\n";
}
template<class InputIterator> void arrin(InputIterator first, InputIterator last) { for (; first != last; ++first) cin >> (*first); }
template<class InputIterator> void arrout(InputIterator first, InputIterator last) {
	for (; first != last; ++first) {
		cout << (*first) << ((first + 1) != last ? " " : "\n");
	}
}

bool pri(lint x) { 
	for (lint i = 2; i * i <= x; ++i) {
		if (x % i == 0) return false;
	}
	return 1 < x; 
}

lint fact[3'000'000];
void fact_init(lint n, lint m = Mod) {
	if (3'000'000 <= n) return;
	fact[0] = fact[1] = 1;
	for (lint i = 2; i <= n; ++i) {
		fact[i] = i * fact[i - 1] % m;
	}
}

lint modpow(lint x, lint n, lint m = Mod) {
	lint res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % m;
		x = x * x % m;
		n >>= 1;
	}
	return res;
}

lint intpow(lint x, lint n) {
	lint res = 1;
	while (n > 0) {
		if (n & 1) res *= x;
		x *= x;
		n >>= 1;
	}
	return res;
}

lint comb(lint n, lint r, lint m = Mod) {
	if (r == 0 || r == n) return 1;
	lint res = fact[n] * modpow(fact[n - r], m - 2, m) % m * modpow(fact[r], m - 2, m) % m;
	return res < 0 ? res + m : res;
}

map<lint, lint> factring(lint n) {
	map<lint, lint> res;
	for (lint i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			n /= i;
			++res[i];
		}
	}
	if (n != 1) ++res[n];
	return res;
}

int main() {
	int n, q;
	cin >> n >> q;

	dsu uf(n);

	rep(i, q) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 0) uf.merge(u, v);
		else cout << uf.same(u, v) << "\n";
	}
}