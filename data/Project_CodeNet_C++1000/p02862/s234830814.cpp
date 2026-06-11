#include <iostream>
#include <vector>

using namespace std;
#define ll long long

ll MOD = 1e9 + 7;

vector<ll> fac, inv, finv;
void COMinit(int m) {
    fac.resize(m);
    finv.resize(m);
    inv.resize(m);
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < m; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll COM(int n, int k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    int X, Y;
    cin >> X >> Y;
    if((X + Y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    int n = (X + Y) / 3;
    COMinit(X + Y);
    cout << COM(X - n + Y - n, X - n) << endl;
    return 0;
}