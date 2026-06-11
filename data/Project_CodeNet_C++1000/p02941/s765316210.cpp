#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
priority_queue<pair<int,int> >q;
int a[200001];
int b[200001];
signed main()
{
	int n,mx=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),mx=max(mx,a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]>a[i])
			q.push(make_pair(b[i],i));
		else if(b[i]<a[i])
		{
			printf("-1");
			return 0;
		}
	}
	long long ans=0;
	while(!q.empty())
	{
		int at=q.top().second;
		q.pop();
		int tot=((at==1)?b[n]:b[at-1])+((at==n)?b[1]:b[at+1]);
		int time=(b[at]-a[at])/tot;
		if(time==0)
		{
			printf("-1");
			return 0;
		}
		ans+=time;
		b[at]-=time*tot;
		if(b[at]!=a[at])
			q.push(make_pair(b[at],at));
	}
	printf("%lld",ans);
	return 0;
}
