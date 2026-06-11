#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

const int mod = 998244353;
signed main(void)
{
	long long n, m, ans;
	vector<long long> v(100010), cnt(100010);

	cin >> n;
	rep(i, n) cin >> v[i]; 
	rep(i, n) cnt[v[i]]++;
	m = 0;
	rep(i, n) m = max(m, v[i]);
	if (cnt[0] != 1 || v[0] != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	ans = 1;
	for(int i = 1; i <= m; i++)
	{
		if (cnt[i] == 0)
		{
			ans = 0;
			break;
		}
		rep(j, cnt[i])
		{
			ans *= cnt[i - 1] % mod;
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}
