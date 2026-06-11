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
	vector<ll> a(n + 1);
	vector<ll> b(n);
	rep(n + 1, a);
	rep(n, b);
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		if (a[i] <= b[i])
		{
			ans += a[i];
			b[i] -= a[i];
			if (b[i] <= a[i + 1])
			{
				a[i + 1] -= b[i];
				ans += b[i];
			}
			else
			{
				ans += a[i + 1];
				a[i + 1] = 0;
			}
		}
		else
		{
			ans += b[i];
			b[i] = 0;
		}
	}
	
	cout << ans << "\n";
	return 0;
}