#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <cstring>
//#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define F first
#define S second

#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e18;
const int maxn = 1e5 + 7;

struct Dsu {
	int p[maxn];
	void init(int n) {
		for (int i = 1; i <= n; i++) p[i] = i;
	}
	int f(int x) {
		return p[x] == x ? x : p[x] = f(p[x]);
	}
	bool merge(int u,int v) {
		u = f(u);
		v = f(v);
		return u == v ? 0 : p[u] = v;
	}
} dsu;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int n, m, ans;
	cin >> n >> m;
	dsu.init(n);
	ans = n - 1;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v; 
		ans -= (dsu.merge(u, v) > 0);
	}
	cout << ans << "\n";
}
