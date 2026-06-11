#include<cstdio>
#include<algorithm>
#define N 200005
#define LL long long
using namespace std;

struct node
{
	int s,nxt;
}p[N<<1];
int h[N],t[N];
LL f[N];
int n,tot;
void adeg(int x,int y)
{
	p[++tot].s=y; p[tot].nxt=h[x]; h[x]=tot;
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adeg(u,v); adeg(v,u);
	}
	f[n]=1;
	for(i=n-1;i>=1;i--)
	{
		int num=0;
		for(j=h[i];j;j=p[j].nxt)
			if(p[j].s>i) t[++num]=p[j].s;
		//sort(t+1,t+num+1);
		f[i]=f[i+1]+n-i+1;
		for(j=1;j<=num;j++)
			f[i]-=(n-t[j]+1);
	}
	LL ans=0;
	for(i=1;i<=n;i++)
		ans+=f[i];
	printf("%lld\n",ans);
	return 0;
}