#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
bool visited[200002]{};
 
void dfs(int n, vector<vector<int>> &ar){
	cnt++;
	visited[n] = 1;
	for(int x : ar[n]){
		if(!visited[x]) dfs(x, ar);
	}
}

main(){
	int n,m; cin>>n>>m;
	
	vector<vector<int>> ar(n+1);
	for(int i=0; i<m; i++){
		int a,b; cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			cnt = 0;
			dfs(i, ar);
		}
		ans = max(ans,cnt);
	}
	cout<<ans;
}