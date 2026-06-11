#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)



int main()
{
	ll n, m;
	cin >> n >> m;
	vector<ll> a(m);
	rep(i, m) cin >> a[i];
	vector<ll> b(n + 100,-1);
	b[0] = b[1] = 1;
	for (ll i = 0; i < m ; i++)
	{
		b[a[i]] = 0;
	}
	
	for (ll i = 2; i < n + 5; i++)
	{
		if (b[i] != 0)
		{
			b[i] = b[i - 1] + b[i - 2];
		}
		b[i] = b[i] % 1000000007;
	}


	cout << b[n] << "\n";
	return 0;
}