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
	
	ll n, k, q;
	cin >> n >> k >> q;
	vector<ll> x(q);
	rep(q, x);
	vector<ll> y(n, 0);
	for (ll i = 0; i < q; i++)
	{
		y[x[i] - 1]++;
	}
	for (ll i = 0; i < n; i++)
	{
		y[i] = k + y[i] - q;
	}
	for (ll i = 0; i < n; i++)
	{
		if (0 < y[i])
		{
			cout << "Yes" << "\n";
		}
		else
		{
			cout << "No" << "\n";
		}
	}
	return 0;
}