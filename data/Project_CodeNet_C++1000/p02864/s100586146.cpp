#include <bits/stdc++.h>
using namespace std;
const int N = 3e2 + 10;
using ll = long long;
int a[N];
ll f[N][N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for (int i = 1; i <= n + 1; ++i)
	{
		for (int j = 0; j < i; ++j)
			for (int k = 0; k <= j; ++k)
				f[i][j] = min(f[i][j], f[i - k - 1][j - k] + max(a[i] - a[i - k - 1], 0));
	}
	cout << f[n + 1][m];
}
