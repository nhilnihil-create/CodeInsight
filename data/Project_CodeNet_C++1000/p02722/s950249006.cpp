#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int n;
bool ok(int y)
{
	int x=n;
	while(x%y==0)
	{
		x/=y;
	}
	return (x%y)==1;
}
int32_t main()
{
	cin>>n;
	set<int> s;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			s.insert(i);
			s.insert(n/i);
		}
	}
	set<int> s2;
	for(int i=1;i<=sqrt(n-1);i++)
	{
		if((n-1)%i==0)
		{
			s2.insert((n-1)/i);
			s2.insert(i);
		}
	}
	int ans=0;
	for(auto i:s)
	{
		if(ok(i))ans++;
	}
	cout<<ans+s2.size();
	
}