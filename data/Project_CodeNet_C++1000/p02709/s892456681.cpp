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
void dumpf(ld x, int t) { cout << setprecision(t) << fixed << x << endl; }
template <class T>
bool chmax(T &a, const T &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template <class T>
bool chmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
	fill((T *)array, (T *)(array + N), val);
}
inline ll mod(ll a, ll mod) {
	if (a > 0) return a % mod;
	if (a % mod == 0) return 0;
	ll x = -a / mod + 1;
	a += x * mod;
	return a % mod;
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

// 本体

ll dp[2002][2002];

int main() {
	IOS();
	int n;
	cin >> n;
	vector<P> a(n);
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		a[i] = make_pair(x, i + 1);
	}
	sort(a.begin(), a.end(), greater<P>());
	Fill(dp, -INF);
	ll ans = -INF;
	for (int l = 0; l <= n; l++) {
		for (int r = 0; l + r <= n; r++) {
			if (l == 0 && r == 0) {
				dp[0][0] = 0;
				continue;
			}
			ll x = a[l + r - 1].first;
			ll i = a[l + r - 1].second;
			if (l > 0) chmax(dp[l][r], dp[l - 1][r] + x * (i - l));
			if (r > 0) chmax(dp[l][r], dp[l][r - 1] + x * (n - r + 1 - i));
			chmax(ans, dp[l][r]);
		}
	}
	dump(ans);
}
