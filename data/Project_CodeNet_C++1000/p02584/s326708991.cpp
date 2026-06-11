#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ll long long
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define ff first
#define ss second
#define prec(y,x) fixed<<setprecision(y)<<x
#define inf 1e18
#define pi 3.1415926535

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll x, k, d;
	cin >> x >> k >> d;
	ll y = abs(x);
	ll z = y / d;
	if (z > k)
	{
		if (x < 0)
		{
			x = x + k * d;
		}
		else
		{
			x -= k * d;
		}
		cout << abs(x);
	}

	else if (z == k)
	{
		if (x < 0)
		{
			x = x + z * d;
		}
		else
		{
			x -= z * d;
		}
		cout << abs(x);
	}
	else
	{
		if (x < 0)
		{
			x = x + z * d;
		}
		else
		{
			x -= z * d;
		}
		z = k - z;
		if (z % 2 == 0)
		{
			cout << abs(x) << endl;
		}
		else
		{
			if (x < 0)
				cout <<  abs(x + d);
			else
				cout <<  abs(x - d);
		}

	}


	return 0;
}

