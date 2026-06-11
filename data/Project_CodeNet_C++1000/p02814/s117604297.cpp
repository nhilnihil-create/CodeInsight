#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n);
	for(int i =0;i<n;i++)
	{
		cin>>a[i];
	}
	ll lcm = a[0]/2;
	for(int i = 1;i<n;i++)
	{
		a[i]/=2;
		ll g = __gcd(a[i],lcm);
		ll p = lcm;
		lcm = a[i]/g*lcm;
		if(
			lcm>m||
			(lcm/p)%2==0||
			(lcm/a[i])%2==0)
		{
			cout << 0 << endl;
			return 0;
		}
	}
	cout << (m+lcm)/(2*lcm) << endl;
}
