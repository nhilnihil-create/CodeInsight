#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

const int mod = 1e9 + 7; 
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
	ll n, K, ans, mn, mx;
	cin >> n >> K;
	ans = 0;
	mx = n * (n + 1) / 2 - (n - K) * (n - K + 1) / 2;
	mn = K * (K - 1) / 2; 
	for (int k = K; k <= n + 1; k++)
	{
		ans += mx - mn + 1; 
		ans %= mod;
		mx += n - k;
		mn += k;
	}
	cout << ans << endl;
	return 0;
}
