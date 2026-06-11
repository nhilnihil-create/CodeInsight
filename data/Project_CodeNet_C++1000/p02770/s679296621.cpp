#include<iostream>
using namespace std;
int k,q;
long d[5000];
main()
{
	cin>>k>>q;
	for(int i=0;i<k;i++)cin>>d[i];
	for(;q--;)
	{
		long n,x,m;cin>>n>>x>>m;
		long ans=0;
		long a=x,b=x;
		for(int i=0;i<n-1&&i<k;i++)
		{
			long L=(n-i-2)/k+1;
			if(d[i]%m==0)ans+=L;
			b+=d[i]%m*L;
		}
		cout<<n-1-(ans+b/m-a/m)<<endl;
	}
}