#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10 , MOD = 1e9 + 7;
int pow_mod(int x , int n , int mod)
{
	int res = 1;
	while(n)
	{
		if(n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}
int dp[N];
signed main()
{
	int n , k , ans = 0;
	cin >> n >> k ;
	for(int i = k ; i ; i --)
	{
		dp[i] = pow_mod(k / i , n , MOD);
		for(int j = 2 * i ; j <= k ; j += i) dp[i] -= dp[j];
		ans = ans + i * dp[i];
		ans %= MOD;
	}
	cout << (ans + MOD) % MOD << '\n' ;
	return 0;
}