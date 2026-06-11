#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long UL;
const int N=1e5+5;
const int INF=0x3f3f3f3f;
vector<int> G[N];
int Vis[N];
void DFS(int u){
	Vis[u]=1;
	for(int i=0;i<G[u].size();++i){
		int v=G[u][i];
		if(Vis[v]==0) DFS(v);
	}
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(Vis[i]==0){
			DFS(i);
			++cnt;
		}
	}
	cout<<cnt-1<<endl;
    return 0;
}
