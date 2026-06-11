#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;

#define endl "\n"

bool vis[N][3];
vector<int> G[N];
int n,m,S,T;

struct node{
	int now,t;
};

void bfs(){
	node p,q;
	p.now=S;
	p.t=0;
	vis[p.now][p.t]=1;
	queue<node> Q;
	Q.push(p);
	while(!Q.empty()){
		q=Q.front();
		Q.pop();
		if(q.now==T&&q.t%3==0) {
			cout<<q.t/3<<endl;
			return;
		}
		int t=(q.t+1)%3,v=q.now,u;
		for(int i=0;i<G[v].size();i++){
			u=G[v][i];
			if(!vis[u][t]){
				vis[u][t]=1;
				p.now=u;
				p.t=q.t+1;
				Q.push(p);
			}
		}
	}
	cout<<-1<<endl;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	memset(vis,0,sizeof(vis));
	int v,u;
	while(m--){
		cin>>v>>u;
		G[v].push_back(u);
	}
	cin>>S>>T;
	bfs();
	return 0;
}