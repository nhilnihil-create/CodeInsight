#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
#define N 200005
#define ll long long 
#define fst first
#define snd second
//环：1:2,n n:n-1,1 
int n,a[N],b[N];
ll ans;//记得开ll 
inline int rd()
{
	int f=1,x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=-f;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f*x;
}
priority_queue<pair<int,int> >Q;
//pair定义优先队列 先按first 再按second 自动排序 
int main()
{
	//freopen("hopeless.in","r",stdin);
	//freopen("hopeless.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;i++)
		a[i]=rd();
	for(int i=1;i<=n;i++)
	{
		b[i]=rd();
		if(a[i]!=b[i]) Q.push(make_pair(b[i],i));
	}
	while(!Q.empty())
	{
		pair<int,int> now=Q.top();Q.pop();
		int i=now.snd;
		/*int pre=i-1,suf=i+1;
		if(pre==0) pre=n;
		if(suf==n+1) suf=1;
		int step=(b[i]-a[i])/(b[pre]+b[suf]);
		*/
		int pre=(i+n-2)%n+1,suf=i%n+1;
		int step=(b[i]-a[i])/(b[pre]+b[suf]);
		if(b[i]-b[pre]-b[suf]<a[i])
		{
			puts("-1");
			return 0;
		}
		ans+=step;
		b[i]-=step*(b[pre]+b[suf]);
		if(a[i]!=b[i]) Q.push(make_pair(b[i],i));
	}
	printf("%lld\n",ans);
    return 0;
}