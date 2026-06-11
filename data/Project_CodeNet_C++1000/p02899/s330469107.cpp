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
	vector<ll> a(n);
	rep(n, a);
	vector<ll> ans(n);
	for (ll i = 0; i < n; i++)
	{
		ans[a[i] - 1] = i + 1;
	}
	for (ll i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}