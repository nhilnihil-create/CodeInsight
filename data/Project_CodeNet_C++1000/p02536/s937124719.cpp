#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>

using namespace std;
vector<bool> visited;
vector<vector<int> > graph;
void dfs(int u){
	visited[u] = true;
	for(int i = 0; i  < (int)graph[u].size(); i++){
		if(!visited[graph[u][i]]){
			dfs(graph[u][i]);
		}
	}
}
int main(){
	int n, m; cin>>n>>m;
	graph.resize(n);
	visited.resize(n);
	for(int i = 0; i < m; i++){
		int a, b; cin>>a>>b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			dfs(i);
			ans++;
		}
	}
	cout<<ans - 1;
}
