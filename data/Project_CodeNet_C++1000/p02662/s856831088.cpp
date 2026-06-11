#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 3e3 + 5;
const int mod = 998244353;
int n, s, a[M], dp[M][M], inv2, pown;

int power(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1)	
			res = (res * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return res % mod;
}

int modInv(int a)
{
	return power(a, mod - 2);
}

int solve(int i, int sum)
{
	if(sum > s)	return 0;

	if(i == n)
	{
		if(sum == s)	return pown;	// 2^n
		return 0;
	}

	if(dp[i][sum] != -1)	return dp[i][sum];

	int ans = solve(i + 1, sum);
	ans += inv2 * solve(i + 1, sum + a[i]);
	ans %= mod;

	return dp[i][sum] = ans;
}
 
int32_t main() 
{
	ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
	cin >> n >> s;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	memset(dp, -1, sizeof dp);
	inv2 = modInv(2);
	pown = power(2, n);
	cout << solve(0, 0);
    	return 0;
}