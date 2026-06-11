#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll GCD(ll a, ll b)
{
	if (b == 0) return a;
	else return GCD(b, a%b);
}

int main(int argc, char **argv)
{
	ll n;
	cin >> n;
	vector<ll> x(n), y(n);
	for (int i = 0;i < n; ++i)
		cin >> x[i] >> y[i];

	if (n == 1)
	{
		std::cout << 1 << std::endl;
		return 0;
	}

	ll res{n};
	for (int i = 0; i < n; ++i )
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j) continue;
			ll dx = x[i] - x[j];
			ll dy = y[i] - y[j];

			ll c{0};
			for (int ii = 0 ;ii < n; ++ii)
			{
				for (int jj = 0; jj < n; ++jj)
				{
					if (ii == jj) continue;
					if (x[ii] - x[jj] == dx && y[ii] - y[jj] == dy)
						++c;
				}
			}
			res = min(res, n-c);
		}
	}

	std::cout << res << std::endl;
}