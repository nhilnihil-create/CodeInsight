#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define inf 1e9
#define INF 1000000000000000000

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    ll MOD = pow(10, 9) + 7;
    vector<ll> zeros(60, 0), ones(60, 0);

    rep(i, N) {
        ll a;
        cin >> a;
        rep(j, 60) {
            if (a & ((ll)1 << j))
                ones[j]++;
            else
                zeros[j]++;
        }
    }

    ll res = 0;
    rep(i, 60) {
        res += zeros[i] * ones[i] % MOD * modpow(2, i, MOD), res %= MOD;
    }

    cout << res << endl;
}