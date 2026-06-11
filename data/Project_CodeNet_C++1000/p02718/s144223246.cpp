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
	ll n,m, ans;
	ans = 0;
	cin >> n >> m;
	vector<ll> a(n);
	rep(i, n)
	{
		cin >> a[i];
	}
	ll sum = 0;
	rep(i, n)
	{
		sum += a[i];
	}

	rep(i, n)
	{
		if (sum <= 4 * m * a[i])
		{
			ans++;
		}
	}

	if (m <= ans)
	{
		cout << "Yes" << "\n";
	}
	else
	{
		cout << "No" << "\n";
	}

	return 0;
}