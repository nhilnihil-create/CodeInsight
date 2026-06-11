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
	ll n, m;
	cin >> n >> m;
	vector<ll> a(m);
	rep(i, m)
	{
		cin >> a[i];
	}
	ll sum = 0;
	rep(i, m)
	{
		sum += a[i];
	}
	if (sum <= n)
	{
		cout << n - sum << "\n";
	}
	else
	{
		cout << "-1" << "\n";
	}


	return 0;
}