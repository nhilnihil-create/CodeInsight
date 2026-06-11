#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define mod 1000000007

LL n, k, ans;

LL power(LL x, LL y) { 
    LL res = 1;
    x = x % mod;

    while (y > 0) { 
        if (y & 1) 
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod; 
    } 
    return res; 
} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> k;
    LL dp[k + 1];

    for(int i = k; i > 0; i--) {
    	dp[i] = power(k / i, n);
    	for(int j = i + i; j <= k; j += i) dp[i] -= dp[j];
    	ans = (ans + (1LL * i * dp[i]) % mod) % mod;
    }
    cout << (ans + mod) % mod;
}