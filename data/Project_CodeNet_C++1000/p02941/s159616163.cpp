#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[201001],b[201001],nxt[201001],pre[201001];
priority_queue<pair<long long,int> >q;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
		q.push(make_pair(b[i],i));
	}
	for(int i=1;i<=n;i++)
	{
		pre[i]=i-1;
		nxt[i]=i+1;
	}
	pre[1]=n;
	nxt[n]=1;
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(b[x]==a[x])continue;
		int l=pre[x],r=nxt[x];
		if(b[x]-b[l]-b[r]<a[x])
		{
			printf("-1");
			return 0;
		}
		int tmp=(b[x]-a[x]),t=tmp/(b[l]+b[r]);
		ans+=t;
		b[x]-=t*(b[l]+b[r]);
		if(b[x]==a[x])continue;
		q.push(make_pair(b[x],x));
	}
	printf("%lld",ans);
}