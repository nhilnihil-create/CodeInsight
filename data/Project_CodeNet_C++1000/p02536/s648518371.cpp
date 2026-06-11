#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edge;
vector<bool> visited;

void dfs(int v) {
	visited[v] = true;
  	for(int u : edge[v]) {
    	if(!visited[u])
          dfs(u);
    }
}

int main() {
  int n, m;
  cin >> n >> m;
  
  edge.resize(n);
  visited.resize(n);
  
  while(m--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  
  int j = 0;
  for(int i = 0; i < n; i++) {
  	if(!visited[i]) {
    	int c = 1;
      	dfs(i);
      	j++;
    }
  }
  cout << j - 1;
}
  
  