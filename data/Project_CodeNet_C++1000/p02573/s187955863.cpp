#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int fa[N],s[N],n,m;
int find(int x){
	if(x==fa[x])return x;
	else return fa[x]=find(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		fa[i]=i;
		s[i]=1;
	}
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		x=find(x),y=find(y);
		if(x!=y){
			fa[x]=y;
			s[y]+=s[x];
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(fa[i]==i){
			res=max(res,s[i]);
		}
	}
	printf("%d\n",res);
	return 0;
}