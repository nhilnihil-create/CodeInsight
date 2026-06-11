#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 1e5 + 5, mod = 1e9 + 7;
int n, k, ans, dp[N];
ll sub(int a, int b){
    return (((a - b) % mod) + mod) % mod;
}
int add(int a, int b){
    return (a + b) % mod;
}
int mul(int a, int b){
    return (1ll * a * b) % mod;
}
ll fp(ll b, ll p){
    if(!p) return 1;
    ll res = fp(b, p / 2);
    res = mul(res, res);
    if(p & 1) res = mul(res, b);
    return res;
}
int main()
{
    cin >> n >> k;
    for(int i = k; i > 0; i--){
        dp[i] = add(dp[i], fp(k / i, n));
        for(int j = 1; j <= sqrt(i); j++){
            if(i % j == 0){
                if(j != i)
                    dp[j] = sub(dp[j], dp[i]);
                if(i / j != j && i / j != i)
                    dp[i / j] = sub(dp[i / j], dp[i]);
            }
        }
        ans = add(ans, mul(dp[i], i));
    }
    cout << ans;
    return 0;
}
