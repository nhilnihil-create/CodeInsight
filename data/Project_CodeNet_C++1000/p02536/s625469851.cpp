#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 100005;

vector<int> G[N]; 
int vis[N];
void dfs(int u){
	vis[u]=1;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(vis[v]==0)dfs(v);
	}
}
int main() {
	int n,m;
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u); 
	}
	int cnt=0; 
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(i);
			cnt++;
		}
	}
	cout<<cnt-1<<endl;
    return 0;
}
 