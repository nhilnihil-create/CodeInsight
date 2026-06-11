#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;
#ifdef XVENOM
	#define errp(...) fprintf(stderr, __VA_ARGS__)
	#define dbg(...) errp("[%s]: ", #__VA_ARGS__), dbg_str(__VA_ARGS__)
#else
	#define errp(...)
	#define dbg(...)
#endif
template <typename U, typename V> string to_string (pair<U, V>);
string to_string (const string& e_) { return "\"" + e_ + "\""; }
string to_string (char e_) { return "\'" + string(1, e_) + "\'"; }
string to_string (bool e_) { return e_ ? "true" : "false"; }
template <typename T> string to_string (T e_) {
	string s_ = "[ ";
	for (const auto& x_ : e_) s_ += to_string(x_) + " ";
	return s_ + "]";
}
template <typename U, typename V> string to_string (pair<U, V> e_) {
	return "(" + to_string(e_.first) + ", " + to_string(e_.second) + ")";
}
void dbg_str () { errp(" \n"); }
template <typename U, typename... V> void dbg_str (U u, V... v) {
 	errp(" %s", to_string(u).c_str()); dbg_str(v...);
}
/* --- */
int main() {
	int n;
	scanf("%d", &n);
	vector<int> p (n + 1);
	vector<int> ind (n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) ind[p[i]] = i;
	multiset<int, greater<int>> s;
	multiset<int> t;
	s.insert(0); s.insert(0);
	t.insert(n + 1); t.insert(n + 1);
	ll ans = 0;
	for (int i = n; i >= 1; i--) {
		ll x, y, z, w;
		auto itr1 = s.upper_bound(ind[i]);
		y = *itr1;
		x = *(++itr1);
		auto itr2 = t.upper_bound(ind[i]);
		z = *itr2;
		w = *(++itr2);
		ll v = i * ((y - x) * (z - ind[i]) + (w - z) * (ind[i] - y));
		ans += v;
		s.insert(ind[i]); t.insert(ind[i]);
	}
	printf("%lld\n", ans);
}

