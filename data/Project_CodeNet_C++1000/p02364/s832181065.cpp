//By Vlgd
#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int n,m;
struct edge{
	int u,v,w;
	friend bool operator<(edge a,edge b){return a.w<b.w;}
}e[N];
int f[N/10],ans=0;
int find(int x){return x==f[x]?x:find(f[x]);}
main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e,e+m);
	for(int i=0;i<n;i++) f[i]=i;
	for(int i=0;i<m;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y){
			ans+=e[i].w;
			f[x]=y;
		}
	}
	printf("%d\n",ans);
}
