#include "bits/stdc++.h"
using namespace std;
#define ll long long int
int main()
{
	int n;
	cin>>n;
	vector<ll> a(n);

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	map<ll,ll> mp;

	ll count=0;

	for(int i=0;i<n;i++)
	{
		ll temp=-(a[i]-i);

		count+=mp[temp];

		mp[a[i]+i]++;
	}

	cout<<count<<endl;

	return 0;
}