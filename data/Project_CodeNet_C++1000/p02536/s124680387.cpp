#include <bits/stdc++.h>
#define ull unsigned long long
#define eps 5e-8
#define IT set<node>::iterator 
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int N=1e5+5;
struct edge{
	int next,to;
}e[N*4];
int n,m,cnt,head[N];
bool vis[N];
void add(int u,int v){
	cnt++;	e[cnt].to=v;	e[cnt].next=head[u];	head[u]=cnt;
}
void dfs(int u){
	vis[u]=true;
	for(int i=head[u];i;i=e[i].next){
		int j=e[i].to;
		if(!vis[j])	dfs(j);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);	add(v,u);
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			res++;
			dfs(i);
		}
	}
	printf("%d\n",res-1);
    return 0;
}