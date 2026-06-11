#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector< int > > g;
vector< int > visited;
vector< int > tlist;

void dfs(int v){
	visited[v] = 1;
	
	for(vector< int >::iterator it = g[v].begin(); it != g[v].end(); ++it){
		if(visited[*it] == 0){
			dfs(*it);
		}
	}
	tlist.push_back(v);
	
}

int main(){
	int v, e, s, t;
	
	cin >> v >> e;
	
	g.resize(v);
	visited.resize(v);
	
	for(int i = 0; i < e; ++i){
		cin >> s >> t;
		g[s].push_back(t);
	}
	
	
	for(int i = 0; i < v; ++i){
		if(visited[i] == 0){
			dfs(i);
		}
	}
	
	reverse(tlist.begin(), tlist.end());
	
	for(vector< int >::iterator it = tlist.begin(); it != tlist.end(); ++it){
		cout << (*it) << endl;
	}
	
	return 0;
}