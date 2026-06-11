#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v[100010];
bool vis[100010];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<v[x].size();i++){
		if(!vis[v[x][i]]){
			dfs(v[x][i]);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
			ans++;
		}
	}
	cout<<ans-1<<endl; 
	return 0;
}