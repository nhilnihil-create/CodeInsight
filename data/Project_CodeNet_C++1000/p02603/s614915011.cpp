#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n;
	cin >> n;
	vector<ll> a(n);
	for(auto &i:a)cin >> i;
	vector<ll> b(n),c(n),d(n);

	b[0] = 1000;
	c[0] = b[0]/a[0];
	d[0] = b[0]%a[0];
	for(ll i = 1;i<n;i++)
	{
		for(ll j = 0;j<i;j++)
		{
			b[i] = max(b[i],b[j]);
			b[i] = max(b[i],d[j]+c[j]*a[i]);
		}
		c[i] = b[i] / a[i];
		d[i] = b[i] % a[i];
	}
	ll ans = 0;
	for(ll i = 0;i<n;i++)
		ans = max(ans,b[i]);
	cout << ans << endl;

}
