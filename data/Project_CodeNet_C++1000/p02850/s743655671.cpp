#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


struct Edge {
	int to,id;
};
vector<vector<Edge>> g;
vector<int>ans;
void dfs(int v,int c = -1,int p = -1) {
	int k = 1;
	rep(i,g[v].size()) {
		int u = g[v][i].to,ei = g[v][i].id;
		if(u == p) continue;
		if(k==c)k++;
		ans[ei] = k;k++;
		dfs(u,ans[ei],v);
	}
}
int main() {
	int n;
	cin >> n;
	g.resize(n);
	ans.resize(n);
	rep(i,n-1) {
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].push_back(Edge{b,i});
		g[b].push_back(Edge{a,i});
	}
	dfs(0);
	int maxv = 0;
	rep(i,n-1) {
		maxv = max(maxv,(int)g[i].size());
	}
	cout << maxv << endl;
	rep(i,n-1) cout << ans[i] << endl;

}