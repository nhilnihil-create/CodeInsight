#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000005];
string s;
int  main(void)
{
	cin>>s;
	for(ll i=0;i<s.size();i++)
	{
		a[i+1]=s[i]-'0';
	}
	ll cnt=0,f=0;
	a[0]=0;
	for(ll i=s.size();i>0;i--)
	{
		a[i]=a[i]+f;
		cnt+=min(a[i],10-a[i]);
		if(a[i]>5||a[i]==5&&a[i-1]>=5)
		{
			f=1;
		}
		else
		{
			f=0;
		}
	}
	printf("%lld",cnt+f);
}