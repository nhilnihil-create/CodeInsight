#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long fast_pow(long long a, long long b, long long p){
    long long ans = 1;
    long long base = a % p;
    b = b % (p - 1);
    while (b){
        if (b & 1)
            ans = (ans * base) % p;
        base = (base * base) % p;
        b >>= 1;
    }
    return ans;
}

long long inv(long long a, long long p){
    return fast_pow(a, p - 2, p);
}

long long C(long long n, long long m, long long p){
    if (n < m)
        return 0;
        m = min(m, n - m);
        long long nom = 1, den = 1;
        for (long long i = 1; i <= m; i++){
            nom = (nom * (n - i + 1)) % p;
            den = (den * i) % p;
        }
        return (nom * inv(den, p)) % p;
}

long long lucas(long long n, long long m, long long p){
    if (m == 0)
        return 1;
    return C(n % p, m % p, p) * lucas(n / p, m / p, p) % p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;

    long long ans = 1, base = 2, nn = n;
    while (nn){
        if (nn & 1)
            ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        nn >>= 1;
    }

    ans -= 1LL;
    ans -= lucas(n, a, MOD);
    while (ans < 0)
        ans += MOD;
    ans -= lucas(n, b, MOD);
    while (ans < 0)
        ans += MOD;

    cout << ans << '\n';

    return 0;
}
