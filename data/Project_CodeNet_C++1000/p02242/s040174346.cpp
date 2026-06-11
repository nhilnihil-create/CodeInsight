#include<iostream>
#include<algorithm>
#define inf 10000000
#define W 0
#define G 1
#define B 2
using namespace std;
int n,color[100];
int g[100][100],d[100],p[100];

void dikstr(int st){
int u,i,j;
	for(i=0;i<n;i++){
	color[i]=W;d[i]=inf;
	}
	d[st]=0;
	p[st]=-1;
	while(true){
	int mincost=inf;
		for(i=0;i<n;i++){
			if(color[i]!=B && d[i]<mincost){
			mincost=d[i];
				u=i;
			}
			
		}
		if(mincost==inf)
		break;
		color[u]=B;
		for(int v=0;v<n;v++){
			if(color[v]!=B && g[u][v]!=inf){
				if(d[u]+g[u][v]<d[v]){
				d[v]=d[u]+g[u][v];
					p[v]=u;
					color[v]=G;
				}
			}
		}
	}
}
main(){
	int i,j,u,k,c,v;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		g[i][j]=inf;
	}
	for(i=0;i<n;i++){
	cin>>u>>k;
		for(j=0;j<k;j++){
		cin>>v>>c;
			g[u][v]=c;
		}
	}
	dikstr(0);
	
	for(i=0;i<n;i++)
	cout<<i<<" "<<d[i]<<endl;
	return 0;
}

