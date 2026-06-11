#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
#include<iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(n,x) for(ll i=0;i<n;i++) cin>>x[i];


int main()
{
	ll n;
	cin >> n;
	vector<ll> h(n);
	rep(n, h);
	ll ans = 0;
	vector<bool> tf(n,false);

	for (ll i = 0; i < n-1; i++)
	{
		if (h[i+1] <= h[i])
		{
			tf[i] = true;
		}
	}
	ll p = 0;
	for (ll i = 0; i < n; i++)
	{
		if (tf[i])
		{
			p++;
		}
		else
		{
			if (ans < p)
			{
				ans = p;
			}
			p = 0;
		}
	}

	cout << ans << "\n";
	return 0;
}