#include<bits/stdc++.h>
using namespace std;
int n, d, A;
struct az
{
	int x;
	int h;
}q[200005];

int l[200005];
long long f[200005];
long long sum[200005];

bool cmp(az a, az b)
{
	return a.x < b.x;
}
int main()
{
	scanf("%d%d%d",&n,&d,&A);
	for(int i=1;i<=n;++i)
	    scanf("%d%d",&q[i].x,&q[i].h);
	sort(q+1,q+1+n,cmp);
	int s=1;
    for(int i=1;i<=n;++i)
    {
    	while(s<n && q[s+1].x-q[i].x <= 2*d) ++s;
    	l[i]=s;
    }
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		sum[i]=sum[i-1]+f[i];
		double p=q[i].h - sum[i] *A;
		//cout<<p<<" "<<i<<endl;
		if (p > 0) 
		{
			f[i] += ceil(p/A);
			f[l[i]+1] -=ceil(p/A);
			sum[i] += ceil(p/A);
			ans+=ceil(p/A);
		}
	}
	cout<<ans<<endl;
	return 0;
}