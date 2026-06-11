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
	ll n, ans;
	cin >> n;
	ans = 0;
	rep(i, n+1)
	{
		if (i % 3 != 0 && i % 5 != 0)
		{
			ans += i;
		}
	}
	cout << ans << "\n";
	return 0;
}