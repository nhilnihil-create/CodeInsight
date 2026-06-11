#include<bits/stdc++.h>
using namespace std;
const int max_n=200005;
int a[max_n],b[max_n];
long long sum1[max_n],sum2[max_n];
long long max(long long a,long long b)
{
	return a>=b?a:b;
}
int main()
{
	int ans=0;
	long long n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum1[i]=sum1[i-1]+a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		sum2[i]=sum2[i-1]+b[i];
	}
	for(int i=0;i<=n;i++)
	{
		if(sum1[i]<=k)
		ans=max(ans,i+upper_bound(sum2+1,sum2+1+m,k-sum1[i])-sum2-1);
		else break;
	}
	cout<<ans<<endl;
}