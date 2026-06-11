#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,l,r) for(int i=l;i<r;i++)
using ll = long long;
const int inf=2e9+10;
const ll MOD=1e9+7;
const ll INF=9e18+10;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

int n;
void bfs(int ans[],vector<int> adj[],int i){
	int dis[n];
	for(int j=0;j<n;j++)dis[j]=inf;
	queue<int> q;
	q.push(i);
	dis[i]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		rep(j,adj[u].size()){
			int v=adj[u][j];
			if(dis[v]!=inf)continue;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
	for(int j=i;j<n;j++){
		ans[dis[j]]++;
	}


	return;
}
//iとi~n-1の点間の最短距離を求める(重複を避けるため)
//そしてきちんとansに記録

void solve(int ans[],vector<int> adj[]){
	for(int i=0;i<n;i++){
		bfs(ans,adj,i);
	}
}

int main(){
	int x,y;
	cin>>n>>x>>y;
	vector<int> adj[n];
	for(int i=1;i<n;i++){
		adj[i].emplace_back(i-1);
		adj[i-1].emplace_back(i);
	}
	--x;--y;
	adj[x].push_back(y);
	adj[y].push_back(x);
	int ans[n];//最短期よりが1-n-1になるものの数
	for(int i=1;i<n;i++)ans[i]=0;

	solve(ans,adj);
	for(int i=1;i<n;i++){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}