#include<bits//stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
ll n,k;
const int MAX = 510000;
const int MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];
void COMint() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main() {
    COMint();
    cin >> n >> k;
    rep(i, k) {
        cout << COM(n - k + 1, i+1) * COM(k - 1, i) % MOD << endl;
    }
}