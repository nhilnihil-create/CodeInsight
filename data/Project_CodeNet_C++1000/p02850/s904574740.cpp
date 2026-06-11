#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct edge{
	int color, to, id;
};
vector<int> ans;
int max_k = 1;

void dfs(int v, int p, int par_col, vector<vector<edge>> &G){
	int col = 1;
	for(auto nv : G[v]){
		if(nv.to == p) continue;
		if(col == par_col) ++col;
		nv.color = col++;
		ans[nv.id] = nv.color;
		chmax(max_k, nv.color);
		dfs(nv.to, v, nv.color, G);
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ans.resize(n);
	vector<vector<edge>> G(n);
	rep(i,n-1){
		int a, b;
		cin >> a >> b;
		--a; --b;
		edge e;
		e.color = -1, e.to = b, e.id = i;
		G[a].push_back(e);
		e.to = a;
		G[b].push_back(e);
	}
	dfs(0, -1, -1, G);
	cout << max_k << endl;
	rep(i,n-1) cout << ans[i] << endl;
	return 0;
}