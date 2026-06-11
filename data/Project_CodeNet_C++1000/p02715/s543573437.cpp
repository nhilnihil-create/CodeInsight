#include<bits/stdc++.h>

using namespace std;

long long n, k;
long long f[100010];
const long long mod = 1e9 + 7;
long long power(long long a, long long b)
{
	return b? power(a*a%mod, b/2)*(b%2?a:1)%mod:1;
} 
int main()
{
	cin >> n >> k;
	long long ans = 0;
	for(int i = k; i >= 1; i--)
	{
		f[i] = power(k/i, n);
		for(int j = 2 * i; j <= k; j += i)
		{
			f[i] -= f[j];
		}
		ans = (ans + i * f[i] %mod)%mod;
	}
	cout << (ans+mod) % mod <<endl;
	return 0;
}
