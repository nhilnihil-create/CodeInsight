#include<bits/stdc++.h>
#define pb push_back
using namespace std;
long long dis[10002];
bool vis[10002];
vector<int> a[10002];
vector<int> b[10002];
int n,u,k,x,t=1,w,m,s,v;
queue<int> q;
int main(){
	cin>>n;
	memset(vis,false, sizeof(vis));
	memset(dis,0x1f1f1f1f,sizeof(dis));
	for (int i=0; i<n; i++){
		cin>>u>>k;
		while (2*k--){
			  cin>>v>>w;
			  a[u].pb(v);
		      b[u].pb(w);
		}
	}
	q.push(0);
	dis[0]=0;
	while (!q.empty()){
		  x=q.front(); q.pop(); vis[x]=false;
		  for (int i=0; i<a[x].size(); i++){
		  	  if (dis[a[x][i]]>dis[x]+b[x][i]){
		  	  	  dis[a[x][i]]=dis[x]+b[x][i];
		  	  	  if (!vis[a[x][i]]){
		  	  	  	  vis[a[x][i]]=true;
		  	          q.push(a[x][i]);
                  }
			 }
		  	  
		  }
	}
    for (int i=0; i<n; i++){
		cout<<i<<' '<<dis[i]<<'\n';
	}
	return 0;
}
