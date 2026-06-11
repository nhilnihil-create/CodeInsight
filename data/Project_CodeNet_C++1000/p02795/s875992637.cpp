#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int h, w, n, p, ans;
	cin >> h >> w >> n;
	p = max(h, w);
	ans = n / p;
	if (n % p != 0)
		ans++;
	cout << ans << endl;
	return 0;
}
