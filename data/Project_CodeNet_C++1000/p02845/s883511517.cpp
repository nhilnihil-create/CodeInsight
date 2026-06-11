#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

const int mod = 1000000007;
signed main(void)
{
	int n;
	cin >> n;
	int a[n];
	rep(i, n) cin >> a[i];
	long long ans;
	vector<int> c(n + 1);

	ans = 1;
	c[0] = 3;
	rep(i, n)
	{
		ans *= c[a[i]];
		ans %= mod;
		c[a[i]]--;
		c[a[i] + 1]++;
	}
	cout << ans << endl;
	return 0;
}
