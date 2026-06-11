#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ii pair<int,int>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

const int maxn = 1e5+10;
const int mod = 1e9+7;

int n;
vii g[maxn];
int ans[maxn];

void dfs(int u,int p,int color,int& maxc){
	int c=0;
	for(auto &w:g[u]){
		int v=w.ff,e=w.ss;
		if(v==p)
			continue;
		if(c+1==color)
			++c;
		ans[e] = ++c;
		dfs(v,u,c,maxc);
	}
	maxc=max(maxc,c);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int a,b;
		cin>>a>>b;
		g[a].pb(ii(b,i));
		g[b].pb(ii(a,i));
	}
	int maxc=0;
	dfs(1,0,-1,maxc);
	cout<<maxc<<endl;
	for(int i=1;i<n;++i){
		cout<<ans[i]<<endl;
	}
	return 0;
}
