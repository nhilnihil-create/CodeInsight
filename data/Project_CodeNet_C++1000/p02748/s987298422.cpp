#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int A, B, m;
	cin >> A >> B >> m;
	int a[A], b[B];
	int x[m], y[m], c[m];
	int ans, min_a, min_b;
	min_a = min_b = 1e9;
	rep(i, A) 
	{
		cin >> a[i];
		min_a = min(a[i], min_a);
	}
	rep(i, B)
	{
		cin >> b[i];
		min_b = min(b[i], min_b);
	}
	ans = min_a + min_b; 
	rep(i, m)
	{
		cin >> x[i] >> y[i] >> c[i];
		x[i]--; y[i]--;
		ans = min(ans, a[x[i]] + b[y[i]] - c[i]);
	}
	cout << ans << endl;
	return 0;
}
