#include <bits/stdc++.h>

using namespace std;

vector<int> g[100005];
bool used[100005];
void dfs(int u) {
  used[u] = 1;
	for(auto to : g[u]) {
    	if(!used[to])
    		dfs(to);
    }
}

int main() {
	int n, m;
  cin>>n>>m;
  while(m--) {
  	int u, v;
    cin>>u>>v;
    --u,--v;
  g[u].push_back(v);
    g[v].push_back(u);
    
  }
	int res =0;
  for(int i =0 ; i < n; ++i) {
  	if(!used[i]) {
    		dfs(i);
      ++res;
    	}
  
  }
	cout<<res-1;
}