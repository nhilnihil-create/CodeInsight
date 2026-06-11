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
	ll n, k;
	cin >> n >> k;
	vector<ll> h(n);
	rep(i, n) cin >> h[i];

	sort(h.begin(), h.end(),greater<ll>());
	ll ans = 0;
	for (int i = k; i < n; i++)
	{
		ans += h[i];
	}

	cout << ans << "\n";
	return 0;
}