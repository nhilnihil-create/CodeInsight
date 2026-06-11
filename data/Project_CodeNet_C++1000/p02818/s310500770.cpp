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
	ll a, b, k;
	cin >> a >> b >> k;
	if (k <= a)
	{
		cout << a - k << " " << b << "\n";
	}
	else
	{
		if (k <= a + b)
		{
			cout << '0' << " " << a + b - k << "\n";
		}
		else cout << 0 << " " << 0 << "\n";
	}
	return 0;
}