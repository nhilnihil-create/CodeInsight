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
	ll n, k;
	cin >> n >> k;
	vector<ll> h(n);
	rep(i, n) cin >> h[i];
	ll ans = 0;
	rep(i, n)
	{
		if (k <= h[i]) ans++;
	}


	cout << ans << "\n";


	return 0;
}