#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
#endif

	int n,k;
	cin>>n>>k;
	vector<ll> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	if(k>=n)
	{
		cout<<0<<endl;
	}
	else
	{
		ll sum=0;
		for(int i=0;i<n-k;i++)
		{
			sum+=a[i];
		}
		cout<<sum<<endl;
	}

	return 0;
}