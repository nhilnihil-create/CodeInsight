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
		//cout<<id<<" "<<ib<<endl;
		if(ib==a[id]) continue;
		int pre=(id-1+n)%n;int suf=(id+1+n)%n;
		if(pre==0) pre=n;if(suf==0) suf=n;
		//cout<<pre<<" "<<suf<<endl; 
		//cout<<b[pre]<<" "<<b[suf]<<" "<<a[id]<<" "<<ib<<endl;
		if((ib-b[pre]-b[suf]-a[id])<0)
		{
			puts("-1");return 0;
		}
		int stp=(ib-a[id])/(b[pre]+b[suf]);ans+=stp;
		//cout<<ans<<endl;
		ib-=1ll*stp*(b[pre]+b[suf]);
		b[id]=ib;
		if(a[id]!=ib) q.push({ib,id});
	}
	cout<<ans<<endl;
}
