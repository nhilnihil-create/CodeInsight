#include <bits/stdc++.h>
using namespace std;
const int N = 100005, MOD = 1E9 + 7;
int n, m, a[N], ans[N];
int main(int argc, char const *argv[])
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int u;
		cin >> u;
		a[u] = 1;
	}
	ans[0] = 1;
	ans[1] = (a[1] == 0);
	for (int i = 2; i <= n; ++i)
	{
		if (a[i])
			continue;
		ans[i] = (1LL * ans[i - 1] + 1LL * ans[i - 2]) % MOD;
	}
	cout << ans[n] << '\n';
	return 0;
}