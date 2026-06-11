#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
const int MOD = 1000000007;

int n, a, b;

int mod_pow(int x, int n) {
    int res = 1;
    while (n>0) {
        if (n&1) res = res*x%MOD;
        x = x*x%MOD;
        n >>= 1;
    }
    return res;
}

const int MAX = 201000;
int fact[MAX], finv[MAX], inv[MAX];

void Cinit() {
    fact[0] = fact[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i=2; i<MAX; i++) {
        fact[i] = fact[i-1]*i%MOD;
        inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}

int C(int n, int k) {
    if (n<k) return 0;
    if (n<0 || k<0) return 0;
    return fact[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    int ans = mod_pow(2, n);
    Cinit();
    int nca = 1;
    for (int i=n; i>=n-a+1; i--) {
        nca *= i;
        nca %= MOD;
    }
    nca *= finv[a];
    nca %= MOD;
    int ncb = 1;
    for (int i=n; i>=n-b+1; i--) {
        ncb *= i;
        ncb %= MOD;
    }
    ncb *= finv[b];
    ncb %= MOD;
    ans = (ans-nca+MOD)%MOD;
    ans = (ans-ncb+MOD)%MOD;
    cout << (ans-1+MOD)%MOD << endl;
}