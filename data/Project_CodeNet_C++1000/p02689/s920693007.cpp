#include <stdio.h>
#define maxn 100010
struct node{
	int to,next;
}e[maxn<<1];
int h[maxn],head[maxn],tot,cnt;
void add_edge(int u,int v){
	tot++,e[tot].to=v,e[tot].next=head[u],head[u]=tot;
}
int main(){
	int n,m,u,v,i,b,flag1,flag2;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&h[i]);
	for(i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	for(i=1;i<=n;i++){
		flag1=0,flag2=0;
		for(b=head[i];b;b=e[b].next){
			flag1=1,v=e[b].to;
			if(h[i]<=h[v]){flag2=1;break;}
		}
		if(!flag1)cnt++;
		else if(!flag2)cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}