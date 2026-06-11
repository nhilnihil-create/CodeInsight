#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
typedef long long ll;
typedef pair<ll,int> pii;
ll a[maxn],b[maxn];
priority_queue<pii> q;
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
		if(a[i]!=b[i]) q.push({b[i],i});
	}
	ll ans=0;
	while(!q.empty())
	{
		pii t=q.top();q.pop();
		ll ib=t.first;int id=t.second;
		//if(ib==a[id]) continue;
		int pre = (id + n - 2) % n + 1, suf = id % n + 1;
		int stp=(ib-a[id])/(b[pre]+b[suf]);
		if(!stp)
		{
			puts("-1");return 0;
		}
		ans+=stp;
		ib-=1ll*stp*(b[pre]+b[suf]);
		b[id]=ib;
		if(a[id]!=ib) q.push({ib,id});
	}
	cout<<ans<<endl;
}