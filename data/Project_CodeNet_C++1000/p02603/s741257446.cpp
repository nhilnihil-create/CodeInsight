#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll n,a[85],m=1000,g=0;cin>>n;
	for(int x=1;x<=n;x++)
	cin>>a[x];
	for(int x=1;x<n;x++)
	{
		if(a[x]<a[x+1])
		{
			g+=(m/a[x]);
			m-=((m/a[x])*a[x]);
		}
		if(a[x]>a[x+1])
		{
			m+=(g*a[x]);
			g=0;
		}
	}
	cout<<m+g*a[n];
	return 0;
}