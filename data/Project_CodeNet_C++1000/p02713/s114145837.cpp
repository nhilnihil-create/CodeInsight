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

int gcd(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}
	else
	{
		return gcd(b, a % b);
	}
}

int main()
{
	int k;
	cin >> k;
	ll ans = 0;
	for (int p = 1; p <= k; p++)
	{
		for (int q = 1; q <= k; q++)
		{
			for (int r = 1; r <= k; r++)
			{
				ans += gcd(p, gcd(q, r));
			}
		}
	}

	cout << ans << "\n";

	return 0;
}