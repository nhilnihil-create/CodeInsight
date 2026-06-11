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
	ll n, m, t;
	cin >> n;
	m = n;
	t = 0;
	while (0 < m)
	{
		t++;
		m /= 10;
	}

	ll ans = 0;
	for (int i = 1; i < t ; i++)
	{
		if (i % 2 == 1)
		{
			ans += 9 * pow(10, i - 1);
		}
	}

	if (t % 2 == 1)
	{
		ans += n - pow(10, t - 1) + 1;
	}

	cout << ans << "\n";

	return 0;
}