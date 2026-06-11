#include <bits/stdc++.h>
typedef long long int LL;
using namespace std;

// 插入此處
namespace Number {
    typedef long long int LL;
    // 求取 a, b 的最大公因數
    LL gcd(LL a, LL b) {
        if (a % b == 0) {
            return b;
        }
        return gcd(b, a % b);
    }
    // 求取 a, b 的最大公因數 gcd
    // 以及 x, y 使得 a*x + b*y = gcd
    LL gcd_extend(LL a, LL b, LL *x, LL *y) { 
        if (a == 0) { 
            *x = 0, *y = 1; 
            return b; 
        } 
    
        LL x1, y1; // To store results of recursive call 
        LL gcd = gcd_extend(b%a, a, &x1, &y1); 
    
        *x = y1 - (b/a) * x1; 
        *y = x1; 
    
        return gcd; 
    }
    // 求 a_inv 使得 (a * a_inv) % m = gcd(a, m)
    // 若 a, m 互質，即求 a 在 mod m 群的反元素 a_inv 
    LL mod_inv(LL a, LL m) { 
        LL x, y; 
        LL g = gcd_extend(a, m, &x, &y); 
        // 處理 x 爲負的情形 
        LL a_inv = (x%m + m) % m; 
        return a_inv;
    }
    // 求 x^n % m
    LL mod_pow(LL x, LL n, LL m) {
        if (n == 0) {
            return 1;
        } else if (n & 1) {
            LL half = mod_pow(x, n/2, m);
            return (half * half % m) * x % m;
        } else {
            LL half = mod_pow(x, n/2, m);
            return half * half % m;
        }
    }
    // 連乘
    LL mul(LL from, LL to, LL m) {
        LL ret = 1;
        for (LL i = from; i <= to; i++) {
            ret *= i;
            ret %= m;
        }
        return ret;
    }
    // 求 (C n 取 k) % m
    LL mod_comb(LL n, LL k, LL m) {
        LL mi = k < n-k ? k : n-k;
        LL up = mul(n - mi + 1, n, m);
        LL down = mul(1, mi, m);
        return (up * mod_inv(down, m)) % m;
    }
}
  

const int MAXN = 100001 + 2;
const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	int n = s.size();
	LL ans = 0;
	LL dp[MAXN];
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i < MAXN; ++i) {
		dp[i] = dp[i-1] * 3 % MOD;
	}
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
		ans += (s[i] - '0') * dp[n-1-i] * Number::mod_pow(2, cnt, MOD) % MOD;
		ans %= MOD;
		if (s[i] == '1')  ++cnt;
	}
	ans += Number::mod_pow(2, cnt, MOD) % MOD;
	ans %= MOD;
	cout << ans << endl;
	return 0;
}
