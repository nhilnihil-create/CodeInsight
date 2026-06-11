#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

void dfs(const vector< vector<int> > &G, vector<int> &ans, int v, int p = -1) {
	for(auto& u : G[v]) {
		if( u == p ) continue;
		
		ans[u] += ans[v];
		dfs(G, ans, u, v);
	}
}

int main(void) {
	int n, q;
	cin >> n >> q;
	
	vector< vector<int> > G(n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	vector<int> ans(n, 0);
	for(int i = 0; i < q; ++i) {
		int p, x;
		cin >> p >> x;
		p--;
		ans[p] += x;
	}
	
	dfs(G, ans, 0);
	
	for(auto& res : ans) {
		cout << res << " ";
	}
	
	cout << endl;
	
	return 0;
}
