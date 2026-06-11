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
	ll k, x;
	cin >> k >> x;
	ll a, b;
	if (x - k + 1 < -1000000)
	{
		a = -1000000;
	}
	else
	{
		a = x - k + 1;
	}

	if (1000000 < x + k - 1)
	{
		b = 1000000;
	}
	else
	{
		b = x + k - 1;
	}

	for (ll i = a; i < b + 1; i++)
	{
		cout << i << " ";
	}


	return 0;
}