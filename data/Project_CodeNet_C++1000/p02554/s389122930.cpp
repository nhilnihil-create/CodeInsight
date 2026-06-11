#include<iostream>
using namespace std;
int mod=1e9+7;
long long a[100010];
int main()
{
	int n;
	long long x=1,y=1,z=1;
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	x*=10;x%=mod;
    	y*=9;y%=mod;
    	z*=8;z%=mod;
	}
	long long ans=((x-2*y)%mod+z+mod)%mod;
	printf("%lld\n",ans);
}