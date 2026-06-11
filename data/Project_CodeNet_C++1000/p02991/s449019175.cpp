#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int mn=3e5+7;
int dis[mn];
vector<int> to[mn];

queue<int> q;
void bfs(int s)
{
	dis[s]=1;
	q.push(s);
	while(!q.empty()) {
		s=q.front();q.pop();
		for(int i=0;i<to[s].size();++i) {
			int t=to[s][i];
			if(dis[t]) continue;
			dis[t]=dis[s]+1;q.push(t);
		}
	}
}

int main()
{
	int n,m,s,t,u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i) {scanf("%d%d",&u,&v);
		to[u*3].pb(v*3+1),to[u*3+1].pb(v*3+2),to[u*3+2].pb(v*3);
	}
	scanf("%d%d",&s,&t);
	bfs(s*3);
	printf("%d",((dis[t*3]-dis[s*3])%3==0)?(dis[t*3]-dis[s*3])/3:-1);
}