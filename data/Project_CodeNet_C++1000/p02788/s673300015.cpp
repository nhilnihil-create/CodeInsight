#include<bits/stdc++.h>
using namespace std;
long long sum[200000];
int main()
{
	long long n,d,damage;
	cin>>n>>d>>damage;
	std::vector<pair<long long,long long> > v;
	for (long long i = 0; i < n; ++i)
	{
		long long x,h;
		cin>>x>>h;
		v.push_back(make_pair(x,h));
	}
	sort(v.begin(),v.end());
	long long ans = 0;
	for (long long i = 0; i < n; ++i)
	{

		if(i!=0)
			sum[i] += sum[i-1];
		v[i].second = v[i].second-sum[i];
		// printf("%lld -> %lld\n",i,sum[i] );
		if(v[i].second <= 0)
			continue;
		long long l = i, r = n;
		while(l<=r)
		{
			long long m = (l+r)/2;
			// printf("-=--=%lld %lld %lld\n",l,r,m );
			if(v[m].first>v[i].first+2*d)
			{
				// printf("nn\n");
				r = m - 1;
			}
			else
			{
				// printf("op\n");
				l = m + 1;
			}
		}
		// printf("l is %lld for i %lld\n",l,i );
		long long c = 0;
		c = v[i].second/damage;
		if(v[i].second%damage>0)
			c++;
		ans += c;
		long long impact = damage*c;
		// printf("impact %lld\n",impact );
		sum[i] += impact;
		sum[l] -= impact;
		// printf("sum %lld %lld\n",i,sum[i] );
	}
	cout<<ans<<endl;

	
	return 0;
}