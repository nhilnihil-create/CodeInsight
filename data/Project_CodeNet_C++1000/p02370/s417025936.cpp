#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;

int n,m;
bool vis[10005];
vector<int>v,G[10005];

void dfs(int u) {
	vis[u]=1;
	for (auto p:G[u]) {
		if (!vis[p]) dfs(p);
	}
	v.pb(u);
}

int main() {
	cin>>n>>m;
	for (int i=0;i<m;i++) {
		int s,t; cin>>s>>t;
		G[s].pb(t);
	}
	for (int i=0;i<n;i++) if (!vis[i]) dfs(i);
	for (int i=v.size()-1;i>=0;i--) cout<<v[i]<<'\n';
}
