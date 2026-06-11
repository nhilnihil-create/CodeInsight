#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int x[n],y[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>x[i]>>y[i];
	}
	map<pair<int,int>,int> mp;
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i==j)
			{
				continue;
			}
			++mp[make_pair(x[i]-x[j],y[i]-y[j])];
			ans=max(ans,mp[make_pair(x[i]-x[j],y[i]-y[j])]);
		}
	}
	cout<<n-ans<<endl;
	return 0;
}
