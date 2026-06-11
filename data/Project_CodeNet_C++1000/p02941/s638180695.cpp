#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	long long a[n],b[n];
	multiset<pair<long long,int>> memo;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>b[i];
		if (a[i]!=b[i])
		{
			memo.insert(make_pair(b[i],i));
		}
	}
	long long ans=0LL;
	while (memo.size()>0)
	{
		auto i=memo.end();
		--i;
		auto p=*i;
		int l=(p.second-1+n)%n,r=(p.second+1)%n;
		memo.erase(i);
		b[p.second]-=a[p.second];
		if (b[p.second]/(b[l]+b[r])==0)
		{
			cout<<"-1\n";
			return 0;
		}
		ans+=b[p.second]/(b[l]+b[r]);
		b[p.second]%=(b[l]+b[r]);
		b[p.second]+=a[p.second];
		if (a[p.second]!=b[p.second])
		{
			memo.insert(make_pair(b[p.second],p.second));
		}
	}
	cout<<ans<<endl;
	return 0;
}
