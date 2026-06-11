#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
int main()
{
	ll n,a[1000000],flag=0;
	while(cin>>n)
	{
	for(int i=1;i<=n;i++)
		cin>>a[i];
		if(a[1]!=0)
		{
			cout<<"0";
			continue;
		}
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++)
		{
			if(abs(a[i]-a[i-1]>1))
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			cout<<"0";
			continue;
		}
		ll i=2,ans=1,t=0;
		for(;a[i]==1;i++)
			t++;
		for(;i<=n;)
		{
			ll d=a[i],s=1,num=0;
			for(;a[i]==d&&i<=n;i++)
			{
				num++;
				s = (s*t)%mod;
			}
			ans=(ans*s)%mod;
			t=num;
		}
		cout<<ans;
	}
	return 0;
}