#include<bits/stdc++.h>
using namespace std;
long long N,K;
long long a[200005];

int check(long long x)
{
	long long now=0;
	double p=x/10.;
	for(int i=1;i<=N;++i) 
	   now+=(a[i]-1)/p;
	//cout<<now<<" "<<x<<" "<<p<<endl;
	return now <= K ;
}

int main()
{
	scanf("%lld%lld",&N,&K);
	for(int i=1;i<=N;++i)
	    scanf("%lld",&a[i]);
	long long l=1,r=1e10;
	while(l<r)
	{
		long long mid =(l + r )/ 2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	//cout<<l<<endl;
	double p=l/10.;
    l=ceil(p);
	printf("%lld\n",l);
	return 0;
}