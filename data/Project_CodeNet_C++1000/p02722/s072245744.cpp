#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,i,j,a[100001],sum=1;
int main()
{
	cin>>n;
	for(i=1;i*i<n;i++)
	{
		ll k=n-1;
		if(k%i==0)
		{
			if(i*i!=k)
			{
				sum++;
			}
			if(i!=1)
			{
				sum++;
			}
		}
	}
	for(i=2;i*i<=n;i++)
	{
		ll k=n;
		while(k%i==0)
		{
			k/=i;
		}
		if(k!=n&&k%i==1)
		{
			sum++;
		}
	}
	cout<<sum<<"\n";
	return 0;
}