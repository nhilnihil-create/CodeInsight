#include "bits/stdc++.h"
using namespace std;

long long n;

int div_count(long long n)
{
	int ans=0;
	bool prime=true;
	for(int i=1;1ll*i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans+=2;
			if(1ll*i*i==n) ans--;
			prime=false;
		}
	}
	return ans+prime-1;
}

bool ok(long long i)
{
	long long m=n;
	while(m%i==0) m/=i;
	return m%i==1;
}

int main()
{
	cin>>n;

	int ans=div_count(n-1);
	for(int i=2;1ll*i*i<=n;i++)
	{
		if(n%i) continue;
		ans+=ok(i);
		//if(1ll*i*i!=n) ans+=ok(n/i);
	}
	cout<<ans+1;
}