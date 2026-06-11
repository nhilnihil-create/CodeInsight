#include <bits/stdc++.h>
using namespace std;
#define reps(i, a, n) for (int i = (a); i < (n); ++i)
#define rep(i, n) reps(i, 0, n)
#define deps(i, a, n) for (int i = (a); i >= (n); --i)
#define dep(i, n) deps(i, n, 0)
#define inf 2147483647
#define int long long

int m[10000];

signed main(void)
{
	int n, m, ans = 0; cin >> n;
	for (int i = 2, m = n; i*i <= m; i++)
	{
		int j = i;
		while (n % j == 0) ans++, n /= j, j *= i;
		while (n % i == 0) n /= i;
	}
	cout << ans + (n != 1) << endl;
}
