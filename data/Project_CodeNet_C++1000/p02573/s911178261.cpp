#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define _rep(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ll long long 
#define N 200005
int n,m,fa[N],sz[N];
inline int ancestor(int x){return fa[x]==x?x:fa[x]=ancestor(fa[x]);}
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	std::cin>>n>>m;
	rep(i,1,n) fa[i]=i,sz[i]=1;
	rep(i,1,m){
		int x,y; std::cin>>x>>y;
		x=ancestor(x),y=ancestor(y);
		if(x!=y){
			fa[y]=x;
			sz[x]+=sz[y];
		}
	}
	int ret=0;
	rep(i,1,n) ret=std::max(ret,sz[ancestor(i)]);
	std::cout<<ret<<'\n';
	return 0;
}