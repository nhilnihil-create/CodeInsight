#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

ll dp[2010][2010];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	vector<P> p(n);
	rep(i, n) {
		p[i].first = a[i];
		p[i].second = i;
	}
	sort(all(p)); reverse(all(p));
	rep(i, n + 1) {
		rep(j, n + 1) {
			if (i + j > n) continue;
			if (i != 0) chmax(dp[i][j], dp[i - 1][j] + p[i + j - 1].first*abs(p[i + j - 1].second - i + 1));
			if (j != 0) chmax(dp[i][j], dp[i][j - 1] + p[i + j - 1].first*abs(p[i + j - 1].second - n + j));
		}
	}
	ll ans = 0;
	rep(i, n + 1) chmax(ans, dp[i][n - i]);
	cout << ans << '\n';
}