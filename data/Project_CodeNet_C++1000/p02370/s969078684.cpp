#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+9;
int vis[MAX];
stack<int>st;
vector<int>adj[MAX];
void dfs(int s){
	vis[s]=1;
	for(int i=0;i<adj[s].size();i++){
		if(vis[adj[s][i]]!=1)
			dfs(adj[s][i]);
	}
	st.push(s);
}
int main(){
	memset(vis, 0, sizeof(vis));
	int n,m;
	cin>>n>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	for(int i=0;i<n;i++){
		if(vis[i]==0)
			dfs(i);
	}
	while(!st.empty()){
		cout<<st.top()<<"\n";
		st.pop();
	}
//	cout<<"\n";

}
