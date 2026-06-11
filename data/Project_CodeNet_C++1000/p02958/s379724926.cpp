#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	ll n;
	cin >> n;
	vector<ll> p(n);
	rep(i, n) cin >> p[i];

	ll c = 0;
	rep(t, n)
	{
		if (p[t] != t + 1)
		{
			c++;
		}
	}

	if (c <= 2) cout << "YES" << "\n";
	else cout << "NO" << "\n";
	return 0;
}