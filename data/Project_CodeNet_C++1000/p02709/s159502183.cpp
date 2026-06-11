#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#define il inline
#define re register
#define fo(i,j,k) for(register int i=j;i<=k;i++)
#define do(i,j,k) for(register int i=j;i>=k;i--) 
#define inf 0x7fffffff
typedef long long ll;
using namespace std;
il ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f*x;	
}
int t;
struct node
{
	ll val,pos;
}a[2005];
ll dp[2005][2005];
bool cmp(node x,node y){return x.val<y.val;}
int main()
{
    int n=read();
	fo(i,1,n)
	{
		a[i].val=read();
		a[i].pos=i;
	} 
	sort(a+1,a+n+1,cmp);
	fo(i,1,n)
	{
		ll p=a[i].val,s=a[i].pos;
		fo(l,1,n+1-i)
		{
			int r=l+i-1;
			dp[l][r]=max(dp[l+1][r]+p*abs(s-l),dp[l][r-1]+p*abs(s-r));
		}
	}
	printf("%lld\n",dp[1][n]);
}
/*int cnt,h[200010],vis[200010],dis[200010];
struct edge
{
	int v,w,next;
}e[200010*2];
il void add(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=h[u];
	h[u]=cnt;
}*/
/*int cnt,prime[1005],p[1005];
void primes(int n)
{
	memset(p,1,sizeof(p));
	p[1]=0;
	fo(i,2,n)
	{
		if(p[i]) prime[++cnt]=i;
		fo(j,1,cnt)
		{
			if(i*prime[j]>n) break;
			p[i*prime[j]]=0;
			if(i%prime[j]==0) break;
		}
	}
}*/