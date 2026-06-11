#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 1e5+10;
const int INF = 1e9+10;

vector<int> g[maxn];
int p[maxn][3];

void bfs(int x){
	queue<pair<int,int>> q;
	q.push({x,0});
	p[x][0] = 0;
	while(!q.empty()){
		int nxt = q.front().first;
		int moves = q.front().second;
		q.pop();
		for(int i=0;i<g[nxt].size();++i){
			int v = g[nxt][i];
			if(p[nxt][moves]+1 < p[v][(moves+1)%3]){
				p[v][(moves+1)%3] = p[nxt][moves]+1;
				q.push({v,(moves+1)%3});
			}
		}
	}
}

void init(){
	for(int i=0;i<maxn;++i)
		for(int j=0;j<3;++j)
			p[i][j] = INF;
}

void solve(){
	int n,m,s,t;
	init();
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	cin >> s >> t;
	bfs(s);
	if(p[t][0] == INF){
		cout << -1 << '\n';
	}
	else{
		cout << p[t][0]/3 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while(t--){ 
		solve();
	}
	return 0;
}