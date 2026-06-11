#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define PER(j,n,a) for (int j=n-1;j>=a;j--)
#define REP(i,a,n) for (int i=a;i<n;i++)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define show(x) cout<<(x)<<endl
#define UM unordered_map
#define PB push_back
#define V vector
#define EPS 1e-8
typedef unsigned long ul;
typedef long long ll;
typedef string str;
/*FIN*/
const int MAXN = 1e5;
int n,m,cc,a,b;
V<int> adj[MAXN];
V<bool> vis(MAXN,0);

void dfs(int u) {
	vis[u] = 1;
	for(int v : adj[u]) {
		if(!vis[v])
			dfs(v);
	}
}

int main() {
	FAST;
	cin>>n>>m;
	REP(i,0,m) {
		cin>>a>>b;
		a--;b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	cc = 0;
	REP(i,0,n) {
		if(!vis[i]) {
			dfs(i);
			cc++;
		}
	}
	show(cc-1);
	return 0;
}

