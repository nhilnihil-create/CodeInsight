#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mxans = 1e18;
 
int main()
{
	ll n, ans=1, zeros=0; cin >> n;
	vector<ll> arr(n);
	for (ll i=0; i<n; i++)
	{
		cin >> arr[i];
		if (arr[i] == 0)
			zeros++;
	}

	if (zeros > 0)
	{
		cout<<"0\n";
		return 0;
	}

	for (ll i=0; i<n; i++)
	{
		if (arr[i]<=1000000000000000000/ans)
			ans *= arr[i];
		else
		{
			cout<<"-1\n";
			return 0;
		}
	}
	cout<<ans<<"\n";
 
	return 0;
}