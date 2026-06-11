#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

const int mod = 1000000007;

long long calc(long long a, long long b, long long p)
{
	if (b == 0) return 1;
	if (b % 2 == 0)
	{
		long long d = calc(a, b / 2, p);
		return (d * d) % p;
	}
	else
		return (a * calc(a, b - 1, p)) % p;
}

signed main(void)
{
	int n, k;
	long long ans, p, q;

	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	p = q = 0;
	rep(i, n) 
	{
		for(int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				p++;
		}
	}	
	rep(i, n) a.push_back(a[i]);
	rep(i, n) 
	{
		for(int j = n; j < a.size(); j++)
		{
			if (a[i] > a[j])
				q++;
		}
	}
	ans = p * k;
	ans %= mod;
	ans += q * k % mod * (k - 1) % mod * calc(2, mod - 2, mod);
	ans %= mod;
	cout << ans << endl;
	return 0;
}
