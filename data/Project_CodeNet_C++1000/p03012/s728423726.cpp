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
	int n;
	cin >> n;
	vector<int> w(n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
		sum += w[i];
	}
	int ans = 1000000;
	int ss = 0;
	for (int t = 0; t < n; t++)
	{
		ss += w[t];
		if (max(sum - 2 * ss, 2 * ss - sum) < ans)
		{
			ans = max(sum - 2 * ss, 2 * ss - sum);
		}
	}

	cout << ans << "\n";

	return 0;
}