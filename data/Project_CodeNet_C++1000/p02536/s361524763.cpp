#include<cctype>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;int n,m,f[100010],x,y,now;
inline int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
inline LL read()
{
	char c;LL d=1,f=0;
	while(c=getchar(),!isdigit(c)) if(c=='-') d=-1;f=(f<<3)+(f<<1)+c-48;
	while(c=getchar(),isdigit(c)) f=(f<<3)+(f<<1)+c-48;
	return d*f;
}
signed main()
{
	n=read();m=read();
	for(register int i=1;i<=n;i++) f[i]=i;
	for(register int i=1;i<=m;i++) 
	{
		x=read();y=read();
		x=find(x);y=find(y);
		if(x==y) continue;
		f[y]=x;now++;
	}
	printf("%d",n-1-now);
}