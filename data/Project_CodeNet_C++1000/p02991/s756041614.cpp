#include<bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int>adjl[100002];
int dist[100002][3]; 
queue<pair<int,int> >bfs;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	memset(dist,-1,sizeof dist);
	cin >> n >> m;
	for (int i=0;i<m;i++){
		int u, v;
		cin >> u >> v;
		adjl[u].push_back(v);
	}
	cin >> s >> t;
	bfs.push({s,0});
	while (!bfs.empty()){
		int now=bfs.front().first;
		int distnow=bfs.front().second;
		bfs.pop();
		if (dist[now][distnow%3]!=-1) continue;
		dist[now][distnow%3]=distnow;
		for (int next : adjl[now]) bfs.push({next,distnow+1});
	}
	cout << (dist[t][0]==-1 ? -1 : dist[t][0]/3)  << "\n";
}