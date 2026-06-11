#include<bits/stdc++.h>
using namespace std;
int counter[200005];
vector<int>tree[200005];
bool visited[200005];
void dfs(int curr,int add){
	visited[curr] = true;
	counter[curr]+=add;
	for(int i=0; i<tree[curr].size(); i++){
		int child = tree[curr][i];
		if(!visited[child]) dfs(child,counter[curr]);	
	}
}
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1; i<n; i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		counter[a]+=b;
	}
	dfs(1,0);
	for(int i=1; i<=n; i++) cout<<counter[i]<<" ";
}