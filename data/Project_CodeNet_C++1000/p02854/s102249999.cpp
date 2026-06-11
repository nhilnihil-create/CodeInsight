#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n;
	cin >> n;
	long long a[n], sum;
	sum = 100000000000;
	rep(i, n) cin >> a[i];
	rep(i, n - 1) a[i + 1] += a[i];
	rep(i, n - 1)
	{
		sum = min(sum, abs(a[i] - (a[n - 1] - a[i])));
	}
	cout << sum << endl;
	return 0;
}
