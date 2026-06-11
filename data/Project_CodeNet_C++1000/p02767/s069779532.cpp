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
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	int sum;
	int ans = 1000000;
	for (int i = 1; i <= 100; i++)
	{
		sum = 0;
		for (int t = 0; t < n; t++)
		{
			sum += pow(x[t] - i, 2);
		}
		if (sum < ans)
		{
			ans = sum;
		}
	}

	cout << ans << "\n";
	return 0;
}