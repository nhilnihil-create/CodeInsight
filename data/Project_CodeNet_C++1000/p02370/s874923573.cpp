//By Vlgd
#include<bits/stdc++.h>
using namespace std;
const int N=10000;
vector<int>G[N];
queue<int>Q;
list<int>L;
list<int>::iterator it;
int n,m,deg[N]={0},vis[N]={0};
void top(int i){
	Q.push(i);
	while(!Q.empty()){
		int v=Q.front();Q.pop();
		vis[v]=1;
		L.push_back(v);
		for(int i=0;i<G[v].size();i++){
			int u=G[v][i];
			deg[u]--;
			if(deg[u]==0&&!vis[u]) Q.push(u);
		}
	}
}
int main(){
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	for(int i=0;i<n;i++) for(int j=0;j<G[i].size();j++) deg[G[i][j]]++;
	for(int i=0;i<n;i++) if(deg[i]==0&&!vis[i]) top(i);
	for(it=L.begin();it!=L.end();it++) printf("%d\n",*it);
	return 0;	
}

