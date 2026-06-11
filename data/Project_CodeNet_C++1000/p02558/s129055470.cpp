#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#ifdef LOCAL
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string(string(s)); }
string to_string(bool b) { return to_string(int(b)); }
string to_string(char b) { return "'" + string(1, b) + "'"; }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A>
string to_string(A v) {
	string res = "{";
	for (const auto& x : v) res += (res == "{" ? "" : ", ") + to_string(x);
	return res + "}";
}
void debug() { cerr << endl; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug(T...);
}
#define db(...) cerr << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)
#else
#define db(...) 42
#endif
typedef long long ll;
typedef long double ld;
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	dsu d(n);
	while (q--) {
		int t, u, v;
		scanf("%d%d%d", &t, &u, &v);
		if (t == 0) d.merge(u, v);
		else printf("%d\n", (int)d.same(u, v));
	}
}
