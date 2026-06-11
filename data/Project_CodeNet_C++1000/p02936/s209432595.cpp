#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;
const ll MX = 1e18;
const int mod = 1000000007;

vector<int> ki[200005];
vector<int> ans;

void dfs(int v, int p) {//vは今見ているnode,pはvの親
	for (int u : ki[v]) {
		if (u == p) continue;
		ans[u] += ans[v];
		dfs(u, v);
	}
}
int main() {
	int n;
	cin >> n;
	int q;
	cin >> q;
	rep(ni, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		ki[a].push_back(b);
		ki[b].push_back(a);
	}
	ans.resize(n);
	rep(i, q) {
		int p, x;
		cin >> p >> x;
		p--;
		ans[p] += x;
	}
	dfs(0, -1);
	rep(i, n) cout << ans[i] << " ";
}
