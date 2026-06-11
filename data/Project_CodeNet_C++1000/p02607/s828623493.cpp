#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, cnt;
	cin >> n;
	int a[n];
	rep(i, n) cin >> a[i];
	cnt = 0;
	for (int i = 0; i < n; i+=2)
	{
		if (a[i] % 2 == 1)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}
