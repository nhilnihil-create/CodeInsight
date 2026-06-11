#define LOCAL

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define LLINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f

// Copied from Gennady-Korotkevich's template

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string)s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}\n";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto& x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}\n";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + "," + to_string(get<4>(p)) + ")";
}

void debug_out() {
	cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "\n[" << #__VA_ARGS__ << "]:\n", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// End of Gennady-Korotkevich's template 


using llong = long long;
using PII = pair<int, int>;

const llong MOD = 1e9 + 7;
const long double PI = acos(-1.0);

const int N = 100100;
int par[N];

int find_par(int n) {
	if (par[n] == n) return n;
	return par[n] = find_par(par[n]);
}
void union_par(int a, int b) {
	a = find_par(a), b = find_par(b);
	if (a == b) return;
	if (a > b) swap(a, b);
	par[b] = a;
}

int main() {
	IOS;
	for (int i = 0; i < N; i++) par[i] = i;
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--, v--;
		union_par(u, v);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (par[i] == i) cnt++;
	}
	cout << cnt - 1 << "\n";
}