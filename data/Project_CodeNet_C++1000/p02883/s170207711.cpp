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
#include <unordered_map>
#include <unordered_set>
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


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	ll n, k;
	cin >> n >> k;
	vector<ll> a(n), f(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> f[i];
	ll ng = -1, ok = INF;
	while (ok - ng > 1) {
		ll mid = (ng + ok) / 2;
		vector<ll> b = a;
		sort(all(b));
		vector<ll> c(n);
		rep(i, n) c[i] = mid / f[i];
		sort(all(c));
		ll cnt = 0;
		rep(i, n) cnt += max(b[i] - c[i], 0ll);
		if (cnt <= k) ok = mid;
		else ng = mid;
	}
	cout << ok << '\n';
}