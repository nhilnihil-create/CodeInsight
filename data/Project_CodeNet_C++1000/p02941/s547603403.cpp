#include<bits/stdc++.h>
using namespace std;
#define ll long long

queue<ll> q;

ll a[200010],b[200010],n;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (ll i=0;i<n;i++) a[i]=rd();
	for (ll i=0;i<n;i++) b[i]=rd();
	for (ll i=0;i<n;i++) if (b[i]<a[i]) { puts("-1");return 0; }
	ll ans=0;
	for (ll i=0;i<n;i++) q.push(i);
	while (!q.empty())
	{
		ll i=q.front();q.pop();
		ll h1=(i-1+n)%n,h2=(i+1)%n;
		if (b[i]<=b[h1]||b[i]<=b[h2]||b[i]==a[i]) continue;
		if (a[i]>b[h1]&&a[i]>b[h2])
		{
			ll hh=b[i]-a[i];
			if (hh%(b[h1]+b[h2])!=0) { puts("-1");return 0; }
			b[i]=a[i];ans+=hh/(b[h1]+b[h2]);
			continue;
		}
		ll hh=(b[i]-max(b[h1],b[h2])+(b[h1]+b[h2])-1)/(b[h1]+b[h2]);
		b[i]-=hh*(b[h1]+b[h2]);ans+=hh;
		if (b[i]<a[i]) { puts("-1");return 0; }
		q.push(h1);q.push(h2);
	}
	bool flag=true;
	for (ll i=0;i<n;i++) if (b[i]!=a[i]) flag=false;
	if (flag) printf("%lld\n",ans);
	else puts("-1");
	return 0;
}