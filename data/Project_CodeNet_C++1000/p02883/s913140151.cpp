#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[200005];
long long f[200005];

bool cmp(long long x,long long y)
{
	return x > y;
}

int check(long long x)
{
	long long cnt=0;
	for(int i=1;i<=n;++i)
		if(a[i] * f[i] > x)
		   cnt+=a[i]-x/f[i];
	return cnt <= k;
}

int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i)
	    scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)
	    scanf("%lld",&f[i]);
	sort(a+1,a+1+n);
	sort(f+1,f+1+n,cmp);
	long long l=0,r=1e18;
	while(l<r)
	{
		long long mid=(l+r)/2;
		if(check(mid))
		    r=mid;
		else  l=mid+1;
		//cout<<l<<" "<<r<<endl;
	}
	printf("%lld\n",l);
	return 0;
}