#include "bits/stdc++.h"
using namespace std;
const int maxN=1e5+10;
const long long MOD=1e9+7;
int n;
long long k;
long long ans[maxN];
long long res=0LL;
long long fast_mi(long long a,int p)
{
	if(p==0)
	{
		return 1LL;
	}
	long long tmp=fast_mi(a,p>>1);
	tmp=tmp*tmp%MOD;
	if(p&1)
	{
		tmp=tmp*a%MOD;
	}
	return tmp;
}
int main()
{
	cin>>n>>k;
	for(long long x=k;x>=1LL;x--)
	{
		long long multi_num=k/x;
		long long num=fast_mi(multi_num,n);
		for(int i=x+x;i<=k;i+=x)
		{
			num=(num-ans[i]+MOD)%MOD;
		}
		ans[x]=num;
		res=(res+num*x)%MOD;
	}
	cout<<res<<endl;
	return 0;
}
