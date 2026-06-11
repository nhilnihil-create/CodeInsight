#include <bits/stdc++.h>

using namespace std; 
 
#define int long long
#define M 1000000007

map<pair<int,int>,int > col;
vector<int> graph[100010];

void dfs(int i,int mx,int pc,int p){
	if(mx==pc){
		pc=1;
	}
	else{
		pc++;
	}
	for(int j=0;j<graph[i].size();j++){
		if(graph[i][j]!=p){
			col[make_pair(i,graph[i][j])]=pc;
			col[make_pair(graph[i][j],i)]=pc;
			dfs(graph[i][j],mx,pc,i);
			if(pc==mx){
				pc=1;
			}
			else{
				pc++;
			}
		}
	}
}
 
signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin >> n;
	int edges[2][n-1];
	for(int i=0;i<n-1;i++){
		cin >> edges[0][i] >> edges[1][i];
		graph[edges[0][i]].push_back(edges[1][i]);
		graph[edges[1][i]].push_back(edges[0][i]);
	}
	int mx=0,ind;
	for(int i=1;i<=n;i++){
		if(mx<(int)graph[i].size()){
			mx=graph[i].size();
			ind=i;
		}
	}
	dfs(ind,mx,0,-1);
	cout << mx << endl;
	for(int i=0;i<n-1;i++){
		cout << col[make_pair(edges[0][i],edges[1][i])] << endl;
	}
}
