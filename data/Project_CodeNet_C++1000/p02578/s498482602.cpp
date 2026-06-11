#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int,int>

int main()
{
	int n;
	cin>>n;
	int a[n];
	ll ans = 0;
	cin>>a[0];
	int nax = a[0];
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
		if(a[i] < nax)
		{
			ans += (nax-a[i]);
		}
		else
		{
			nax = a[i];
		}
	}
	cout<<ans<<endl;
}