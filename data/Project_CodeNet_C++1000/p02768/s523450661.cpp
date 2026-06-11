#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define dbg(x) cerr << #x << " : " << x << "\n";

const int mod = (int)1e9+7;

ll modInverse(int a)
{
    ll f = 1;
    for(int i = 1; i <= a; i++) {
        f *= i;
        f %= mod;
    }
    int N = mod-2;
    ll res = 1, p = f;
    while(N) {
        if(N & 1) {
            res = res * p;
            res %= mod;
        }
        p = p * p;
        p %= mod;
        N /= 2;
    }
    return res % mod;
}

int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int N = n;
    ll res = 1, p = 2;
    while(N) {
        if(N & 1) {
            res = res * p;
            res %= mod;
        }
        p = p * p;
        p %= mod;
        N /= 2;
    }
    ll tmp = 1;
    for(int i = n; i > n - a; i--){
        tmp = tmp * i;
        tmp %= mod;
    }
    res -= (tmp*modInverse(a))%mod;
    res = (res + mod) % mod;
    tmp = 1;
    for(int i = n; i > n - b; i--) {
        tmp = tmp * i;
        tmp %= mod;
    }
    res -= (tmp*modInverse(b))%mod;
    res--;
    res = (res + mod) % mod;
    printf("%lld\n", res);
}
