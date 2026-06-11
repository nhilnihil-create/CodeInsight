#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	set<ll> a,b;
	ll n, k;
	cin >> n >> k;
	ll  count, p;
	count = 0;
	vector<vector<ll>> v(k,vector<ll>());
	vector<ll> d(k);
	rep(i, k)
	{
		cin >> d[i];
		v[i].resize(d[i]);

		rep(t, d[i])
		{
			cin >> v[i][t];
		}
	}
	vector<bool> tf(n);
	rep(x, n)
	{
		rep(p, k)
		{
			rep(q, d[p])
			{
				if (v[p][q] == x + 1)
				{
					tf[x] = true;
				}
			}
		}
	}
	
	rep(y, n)
	{
		if (tf[y])
		{
			count++;
		}
	}

	cout << n - count << "\n";
	return 0;
}