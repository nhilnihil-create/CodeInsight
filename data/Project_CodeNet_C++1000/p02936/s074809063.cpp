#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

vector<int> g[200005];
vector<long long> ans;
void dfs(int v, int p = -1) {
	for (auto next_v : g[v]) {
		if (next_v == p) continue;
		ans[next_v] += ans[v];
		dfs(next_v, v);
		
	}
}

int main() {
	int n, q;
	cin >> n >> q;

	for (int i = 1;i < n;i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ans.resize(n + 1);
	for (int i = 0;i < q;i++) {
		int p, x;
		cin >> p >> x;
		ans[p] += x;
	}

	dfs(1);
	

	for (int i = 1;i <= n;i++) {
		cout << ans[i] << endl;
	}

	return 0;
}
