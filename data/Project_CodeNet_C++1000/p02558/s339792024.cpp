#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q,p[maxn];
int find(int u)
{
	if(p[u]!=u) p[u]=find(p[u]);
	return p[u];
}
void read(int& ret)
{
	ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+ch-'0',ch=getchar();
}
int main()
{
	read(n),read(q);
	for(int i=1;i<n;i++) p[i]=i;
	while(q--){
		int type,u,v;
		scanf("%d%d%d",&type,&u,&v);
		int root1=find(u),root2=find(v);
		if(!type) p[root2]=root1;
		else {
			if(root1!=root2) printf("0\n");
			else printf("1\n");
		}
	}
}