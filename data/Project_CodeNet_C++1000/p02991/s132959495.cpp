#include<bits/stdc++.h>
using namespace std;
vector<int>g[100005];
int dis[100005][3];
int main(){
	int n,m,s,t,u,v;
	memset(dis,-1,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
	}
	scanf("%d%d",&s,&t);
	queue<pair<int,int> >q;
	q.push({s,0});
	dis[s][0]=0;
	while(!q.empty()){
		int v=q.front().first;
		int l=q.front().second;
		q.pop();
		for(int i=0;i<g[v].size();i++){
			int ll=(l+1)%3;
			if(dis[g[v][i]][ll]>=0)
				continue;
			dis[g[v][i]][ll]=dis[v][l]+1;
			q.push({g[v][i],ll});
		}
	}
	if(dis[t][0]>=0)
		dis[t][0]/=3;
	printf("%d\n",dis[t][0]);
} 