#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;
// 型シノニム
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
// 定数
constexpr ll INF   = 1e16;
constexpr ll INM   = 114514;
constexpr ll MOD   = 1e9 + 7;
constexpr ld EPS   = 1e-12;
constexpr ll dx[4] = {1, 0, -1, 0};
constexpr ll dy[4] = {0, 1, 0, -1};
// 便利関数
void IOS() { ios::sync_with_stdio(false), cin.tie(0); }
template <typename T>
void dump(T x) { cout << x << endl; }
void dumpf(ld x, ll t) { cout << setprecision(t) << fixed << x << endl; }
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
vector<string> split(const string &s, char delim) {
	vector<string> elems;
	string item;
	for (char ch : s) {
		if (ch == delim) {
			if (!item.empty())
				elems.push_back(item);
			item.clear();
		} else {
			item += ch;
		}
	}
	if (!item.empty())
		elems.push_back(item);
	return elems;
}
ll powm(ll a, ll b, ll m) {
	if (b == 0) {
		return 1;
	} else if (b % 2 == 0) {
		ll d = powm(a, b / 2, m);
		return (d * d) % m;
	} else {
		return (powm(a, b - 1, m) * a) % m;
	}
}
inline ll mod(ll a, ll b) {
	if (a > 0) return a % b;
	if (a % b == 0) return 0;
	ll x = -a / b + 1;
	a += x * b;
	return a % b;
}
// 本体

ll dp[3002][3002] = {};

int main() {
	IOS();
	ll n, s;
	cin >> n >> s;
	ll MOD = 998244353;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= s; j++) {
			dp[i + 1][j] = dp[i][j] * 2;
			if (j >= a[i]) {
				dp[i + 1][j] += dp[i][j - a[i]];
			}
			dp[i + 1][j] %= MOD;
		}
	}
	dump(dp[n][s]);
}