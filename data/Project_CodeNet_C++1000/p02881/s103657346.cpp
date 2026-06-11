#include "bits/stdc++.h"
using namespace std;

long long n,ans=LLONG_MAX;

int main()
{
	cin>>n;

	int r=sqrtl(n);
	for(int i=1;i<=r;i++)
	{
		if(n%i) continue;
		long long d1=i,d2=n/i;
		ans=min(ans,d1+d2-2);
	}
	cout<<ans;
}