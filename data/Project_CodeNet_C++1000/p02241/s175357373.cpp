#include<iostream>
#include<algorithm>
#define wh 0
#define gr 1
#define bl 2
#define inf 2001
#define null (-1)
#define Max 100 
using namespace std;
int color[Max],m[Max][Max];
int d[Max],p[Max],n;
void prim(){
int i,j,u;
	for(i=0;i<n;i++){
	color[i]=wh;
		d[i]=inf;
	}
	d[0]=0;
	p[0]=-1;
	while(true){
	int mincost=inf;
		for(i=0;i<n;i++){
			if(color[i]!=bl && d[i]<mincost){
			mincost=d[i];
				u=i;
			}
		}
		if(mincost==inf)
		break;
		color[u]=bl;
		for(int v=0;v<n;v++){
			if(color[v]!=bl && m[u][v]!=null){
				if(m[u][v]<d[v]){
				d[v]=m[u][v];
					p[v]=u;
					color[v]=gr;
				}
			}
		}
	}
}

main(){
	int i,j;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
	cin>>m[i][j];
			m[j][i]=m[i][j];
		}
	}
	prim();
	int ans=0;
	for(i=0;i<n;i++)
	ans+=d[i];
	cout<<ans<<endl;
	return 0;
}

