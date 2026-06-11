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

int trans(int x, int y) {
	if (x > y) swap(x, y);
	return x * 1000 + y;
}

vector<vector<int>> graph(1000010, vector<int>());
vector<bool> vis(1000010), calc(1000010);
vector<int> ans(1000010);

int dfs(int n) {
	if (vis[n]) {
		if (!calc[n]) return -1;
		return ans[n];
	}
	vis[n] = true; ans[n] = 1;
	for (int i : graph[n]) {
		int tmp = dfs(i);
		if (tmp == -1) return -1;
		chmax(ans[n], tmp + 1);
	}
	calc[n] = true;
	return ans[n];
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	rep(i, n) {
		vector<int> a(n - 1);
		rep(j, n - 1) {
			cin >> a[j];
			a[j]--;
		}
		rep(j, n - 2) {
			graph[trans(i, a[j + 1])].pb(trans(i, a[j]));
		}
	}
	int ans = 0;
	rep(i, 1000 * n) {
		int tmp = dfs(i);
		if (tmp == -1) {
			cout << -1 << '\n';
			return 0;
		}
		else {
			chmax(ans, tmp);
		}
	}
	cout << ans << '\n';
}