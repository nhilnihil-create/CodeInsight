#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;

int n,m,fa[MAXN];

int getfa(int Node){
	if(Node==fa[Node])return Node;
	else return fa[Node]=getfa(fa[Node]);
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i;
	while(m--){
		int x,y;
		scanf("%d %d",&x,&y);
		fa[getfa(x)]=getfa(y);
	}
	int u=getfa(1),tot=0;
	for(int i=2;i<=n;++i)
	if(getfa(i)!=u)++tot,fa[getfa(i)]=u;
	printf("%d\n",tot);
	return 0;
}