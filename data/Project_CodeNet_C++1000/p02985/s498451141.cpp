#include<cstdio>
#include<cstring> 
#include<iostream>
#include<set>
using namespace std;
#define N 100005
#define INF 1000000000
#define M 1000000007
int hd[N],nx[2*N],to[2*N],v[N];
long long int fa[N],son[N];
int ls=0;
long long int ans=1;
int n;
long long int k;
void add(int x,int y){
nx[++ls]=hd[x];
hd[x]=ls;
to[ls]=y;

nx[++ls]=hd[y];
hd[y]=ls;
to[ls]=x;
}
void dfs1(int s,int f){
	v[s]=1;
	fa[s]=f;
	for(int i=hd[s];i;i=nx[i])if(!v[to[i]]){
	dfs1(to[i],s);
	}
}
void dfs2(int s){
	long long int ks=k;
	v[s]=0;
	if(fa[s]){
	ks-=son[fa[s]]+1;
	son[fa[s]]++;
	}
	if(fa[fa[s]])ks--;
	ans*=ks;
	ans%=M;
	for(int i=hd[s];i;i=nx[i])if(v[to[i]]){
	dfs2(to[i]);
	}
}
int main(){
memset(son,0,sizeof(son));
memset(v,0,sizeof(v));
memset(hd,0,sizeof(hd));
scanf("%d%lld",&n,&k);
for(int i=1;i<=n-1;i++){
	int x,y;
	scanf("%d%d",&x,&y);
	add(x,y);
}
dfs1(1,0);
dfs2(1);
printf("%lld",ans);
}