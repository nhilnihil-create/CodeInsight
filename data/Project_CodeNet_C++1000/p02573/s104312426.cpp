#include<bits/stdc++.h>
 
using namespace std;

typedef pair<int, int> ii;      
typedef vector<ii> vii;      
typedef vector<int> vi;   
#define DFS_WHITE -1 
#define DFS_BLACK 1
vector<vi> AdjList;
vi dfs_num;     // this variable has to be global, we cannot put it in recursion
vi dfs_discover;
int numCC;
int count = 0;

int dfs(int u) {          // DFS for normal usage: as graph traversal algorithm
//  printf(" %d", u);                                    // this vertex is visited
  	dfs_num[u] = DFS_BLACK;      // important step: we mark this vertex as visited
  	int ans = 1;
  	for (int j = 0; j < (int)AdjList[u].size(); j++) {
    	int v = AdjList[u][j];                      // v is a (neighbor, weight) pair
    	if (dfs_num[v] == DFS_WHITE)         // important check to avoid cycle
      		ans += dfs(v);      // recursively visits unvisited neighbors v of vertex u
 	}
	return  ans; 
}

 
int main(){
	int n, m;
	cin>>n>>m;
	AdjList.assign(n + 1, vi());
	dfs_num.assign(n + 1, DFS_WHITE);
	for (int i=0; i<m; i++){
		int x, y;
		cin>>x>>y;
		AdjList[x].push_back(y);
		AdjList[y].push_back(x);
	}
	int ans = 0;
	for (int i=1; i<=n; i++){
		if(dfs_num[i] == DFS_WHITE){
			ans = max(ans,dfs(i));
		}
	}
	cout<<ans;
}