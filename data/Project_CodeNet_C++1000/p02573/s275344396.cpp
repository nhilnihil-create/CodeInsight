#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int n,m;
vector<int> edges[200005];
bool visited[200005];
int res,ans=-1;
void dfs(int x){
	res++;
	visited[x]=1;
	for(int i=0;i<sz(edges[x]);i++){
		int fr=edges[x][i];
		if(!visited[fr]) dfs(fr);
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	for(int i=1;i<=n;i++){
		res=0;
		dfs(i);
		ans=max(res,ans);
	}
	cout<<ans;
	re 0;
}