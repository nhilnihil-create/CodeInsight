#include<bits/stdc++.h>
using namespace std;
string to_string(const string& s) {
	return '"' + s + '"';
}
string to_string(const bool b) {
	return (b ? "true" : "false");
}
string to_string(const char* s) {
	return to_string((string)s);
}
string to_string(const char c) {
	string s = "'";
	s += c;
	s += "'";
	return s;
}
template<class T, class U>
string to_string(const pair<T, U>& p) {
	string s = "(";
	s += to_string(p.first);
	s += ", ";
	s += to_string(p.second);
	s += ")";
	return s;
}
template<class T>
string to_string(const T& a) {
	bool first = true;
	string s = "{";
	for (const auto& x : a) {
		if(!first){
			s += ", ";
		}
		first = false;
		s += to_string(x);
	}
	s += "}";
	return s;
}
void debug_out() {cerr << '\n';}
template<class Head, class... Tail>
void debug_out(Head head, Tail... tail) {
	cerr << ' ' << to_string(head);
	debug_out(tail...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;
const int inf = 1e9 + 100;
const ll inf64 = 7e18l;
void min_self(ll& x, ll y) {
	x = min(x, y);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(20);
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	a[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i + 1];
	}
	vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(n + 1, vector<ll>(k + 1, inf64)));
	dp[1][1][0] = a[1];
	if (k != 0) {
		dp[1][0][1] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int kk = 0; kk <= k; ++kk) {
				if (a[i] != a[j] && kk != k) {
					min_self(dp[i][j][kk + 1], dp[i - 1][j][kk]);
				}
				if (a[i] == a[j]) {
					min_self(dp[i][j][kk], dp[i - 1][j][kk]);
				}
				min_self(dp[i][i][kk], dp[i - 1][j][kk] + max(a[i] - a[j], 0));
			}
		}
	}
	ll answer = inf64;
	for (int j = 0; j <= n; ++j) {
		for (int kk = 0; kk <= k; ++kk) {
			min_self(answer, dp[n][j][kk]);
		}
	}
	cout << answer << '\n';
	return 0;
}
