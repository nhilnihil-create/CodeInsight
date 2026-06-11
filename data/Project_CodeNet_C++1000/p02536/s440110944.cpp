#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> edges;
void dfs(int src,vector<bool> &visited){
	visited[src]=1;
	for(auto x:edges[src]){
		if(!visited[x]){
			dfs(x,visited);
		}
	}
}
int connectedComponents(int n){
	vector<bool> visited(n+1,0);
	int count=0;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			count++;
			dfs(i,visited);
		}
	}
	return count;
}
void solve(){
	int n,m;
	cin>>n>>m;
	edges.resize(n+1);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	cout<<connectedComponents(n)-1<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
