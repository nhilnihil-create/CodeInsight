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
	ll n, m;
	cin >> n >> m;
	vector<bool> ac(n, false);
	vector<ll> wa(n, 0); 
	
	ll p;
	string s;
	rep(i, m)
	{
		cin >> p >> s;
		if (ac[p - 1] == false)
		{
			if (s == "AC")
			{
				ac[p - 1] = true;
			}
			else
			{
				wa[p - 1]++;
			}
		}
	}

	ll x, y;
	x = y = 0;
	rep(i, n)
	{
		if (ac[i])
		{
			x++;
			y += wa[i];
		}
	}

	cout << x << " " << y << "\n";


	return 0;
}