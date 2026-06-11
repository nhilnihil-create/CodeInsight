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

vector<int> topological_sort(int n, vector<vector<int>> graph) {
	vector<int> indegree(n);
	for (int i = 0; i < n; i++) {
		for (int to : graph[i]) {
			indegree[to]++;
		}
	}
	vector<int> res;
	queue<int> que;
	for (int i = 0; i < n; i++) if (indegree[i] == 0) que.push(i);
	while (!que.empty()) {
		int ver = que.front(); que.pop();
		res.push_back(ver);
		for (int i : graph[ver]) {
			indegree[i]--;
			if (indegree[i] == 0) que.push(i);
		}
	}
	return res;
}

vector<vector<int>> graph(1000010, vector<int>());
vector<int> ans(1000010, 1);

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
		rep(j, n - 2) graph[trans(i, a[j + 1])].pb(trans(i, a[j]));
	}
	vector<int> order = topological_sort(1000 * n, graph);
	if (order.size() != 1000 * n) {
		cout << -1 << '\n';
		return 0;
	}
	rep(i, 1000 * n) {
		for (int nxt : graph[order[i]]) {
			chmax(ans[nxt], ans[order[i]] + 1);
		}
	}
	int res = 0;
	rep(i, 1000 * n) chmax(res, ans[i]);
	cout << res << '\n';
}