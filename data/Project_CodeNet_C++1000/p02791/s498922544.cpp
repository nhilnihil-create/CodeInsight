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
	ll n;
	cin >> n;
	vector<ll> p(n);
	rep(i, n) cin >> p[i];

	ll min = n + 10;
	ll ans = 0;
	rep(i, n)
	{
		if (p[i] < min)
		{
			ans++;
			min = p[i];
		}
	}
	cout << ans << "\n";
	return 0;
}