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
	ll n;
	cin >> n;
	ll ans = 100000000000000001;
	for (ll i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			if (i + (n / i) - 2 < ans)
			{
				ans = i + n / i - 2;
			}
		}
	}

	cout << ans << "\n";
	
	return 0;
}