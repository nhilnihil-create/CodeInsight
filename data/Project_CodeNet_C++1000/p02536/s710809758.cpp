#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+4;
int n,m,fa[N],blo;
inline int find(int x) {
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
inline void merge(int u,int v) {
	int fu=find(u),fv=find(v);
	if (fu^fv) {
		fa[fu]=fv;
		--blo;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for (register int i=1;i<=n;++i) {
		fa[i]=i;
	}
	blo=n;
	for (register int i=0;i<m;++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		merge(u,v);
	}
	printf("%d\n",blo-1);
	return 0;
}