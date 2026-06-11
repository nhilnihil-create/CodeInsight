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
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n - 1);
	rep(n - 1, b);
	a[0] = b[0];
	a[n - 1] = b[n - 2];
	for (ll i = 1; i < n - 1 ; i++)
	{
		a[i] = min(b[i], b[i - 1]);
	}
	ll sum = 0;
	for (ll i = 0; i < n; i++)
	{
		sum += a[i];
	}
	cout << sum << "\n";
	return 0;
}