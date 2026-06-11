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

int f(ll x, ll y)
{
	if (x % y == 0)
	{
		return y;
	}
	else
	{
		return f(y, x % y);
	}
}

int main()
{
	ll a, b;
	cin >> a >> b;
	ll c = f(a, b);
	cout << a * b / c << "\n";

	return 0;
}