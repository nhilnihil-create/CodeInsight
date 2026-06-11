#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second

const int N=1000000000;
vector<vector<int>>adj;
int dis[100005][3];
main() {
	int n, m;
	cin>>n>>m;
	adj.resize(n+1);
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		
	}
	int s, t;
	cin>>s>>t;
	for(int i=1; i<=n; i++){
		for(int j=0; j<3; j++){
			dis[i][j]=N;
		}
	}
	dis[s][0]=0;
	queue<pair<int, int>>q;
	q.push({s, 0});
	while(!q.empty()){
		int node=q.front().f;
		int t1=q.front().s;
		int t2=(t1+1)%3;
		q.pop();
		for(auto u:adj[node]){
			
			if(dis[u][t2]>1+dis[node][t1]){
				dis[u][t2]=1+dis[node][t1];
				q.push({u, t2});
			}
		}
	}
	if(dis[t][0]==N){
		cout<<-1;
		return 0;
	}
	cout<<(dis[t][0])/3;
	return 0;
}