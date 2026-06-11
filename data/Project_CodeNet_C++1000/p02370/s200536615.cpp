#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v[10000];
vector<bool>vis(10000);
stack<int>order;
void dfs(int u){
	vis[u]=1;
	for(auto i:v[u]){
		if(!vis[i])dfs(i);
	}
	order.emplace(u);
}
int main(){
	cin>>n>>m;
	while(m--){
		int l,r;
		cin>>l>>r;
		v[l].emplace_back(r);
	}
	for(int i=0;i<n;i++){
		if(!vis[i])dfs(i);
	}
	while(!order.empty()){
		cout<<order.top()<<"\n";
		order.pop();
	}
}
