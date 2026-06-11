#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,mod=1000000007ll,ans=1ll;
ll a[100005],num[3]={0};

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		ll cnt=0,id;
		cin>>a[i];
		if (a[i]==num[0])
		{
			cnt++;
			id=0;
		}
		if (a[i]==num[1])
		{
			cnt++;
			id=1;
		}
		if (a[i]==num[2])
		{
			cnt++;
			id=2;
		}
		ans*=cnt;
		ans%=mod;
		num[id]++;
	}
	cout<<ans<<endl;
	return 0;
}