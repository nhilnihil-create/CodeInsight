#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int INF=1000000000;
int n,d[100];
int G[100][100];
void dijkstra(int s){
    fill(d,d+n,INF);
    bool used[n]={false};
    d[s]=0;
    while(true){
	int v=-1;
	for(int u=0;u<n;u++){
	    if(used[u]) continue;
	    if(v==-1||d[u]<d[v]) v=u;
	}
	if(v==-1) break;
	used[v]=true;
	
	for(int u=0;u<n;u++){
	    d[u]=min(d[u],d[v]+G[v][u]);
	}
    }
}
int main(){
    cin>>n;
    fill(G[0],G[n],INF);
    for(int i=0;i<n;i++){
	int u,k;
	cin>>u>>k;
	for(int j=0;j<k;j++){
	    int v,c;
	    cin>>v>>c;
	    G[u][v]=c;
	}
    }
    dijkstra(0);
    for(int i=0;i<n;i++){
	cout<<i<<' '<<d[i]<<endl;
    }
    return 0;
}