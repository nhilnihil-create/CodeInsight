#include <iostream>
#define MAXN 100005
using namespace std;

const long long MOD = 1e9 + 7;

long long n, k, dp[MAXN];

long long power(long long x, unsigned long long y)  
{  
    long long res = 1; 
    x = x % MOD;
    if (x == 0) return 0;
  
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % MOD;
        y = y>>1;  
        x = (x*x) % MOD;  
    }  
    return res;  
}  

int main() {
	cin >> n >> k;
	for (long long i=k; i>0; i--) {
		dp[i] = power(k/i, n);
		long long temp = 2*i;
		while (temp <= k) {
			dp[i] -= dp[temp];
			dp[i] = (dp[i] + MOD) % MOD;
			temp += i;
		}
	}
	long long ans = 0;
	for (long long i=1; i<=k; i++) {
		// cout << dp[i] << " ";
		ans += i * dp[i];
		ans %= MOD;
	}
	// cout << "\n";
	cout << ans;
}