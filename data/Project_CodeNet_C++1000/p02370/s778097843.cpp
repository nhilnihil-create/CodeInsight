//Template
#include <bits/stdc++.h>
#define INF INT_MAX
#define MOD 100000007
#define MAX_E 1000000
#define MAX_V 1000000
using namespace std;

int V, E;
vector<int> adj[MAX_V];
int visited[MAX_V];
stack<int> stk;
void DFS(int u){
	visited[u]=2;
	int d=adj[u].size();
	for(int j=0; j<d; ++j){
		if(visited[adj[u][j]]==2){
			printf("Sandro fails.");
			exit(0);
		}
		if(visited[adj[u][j]]==0)
		DFS(adj[u][j]);
	}
	visited[u]=1;
	stk.push(u);
	return;
}
bool cmp(int i, int j){return i>j;}
int main(){
	scanf("%d%d", &V, &E);
	for(int i=0; i<E; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
	for(int i=0; i<V; ++i){
		sort (adj[i].begin(), adj[i].begin()+adj[i].size(), cmp);
	}
	for(int i=0; i<V; ++i){
		if(!visited[i])DFS(i);
	}
	while(!stk.empty()){
		cout<<stk.top()<<endl;
		stk.pop();
	}
	return 0;
}
/*
8 9
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6
*/
