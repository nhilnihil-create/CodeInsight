#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;
const int MAX = 1111111;

int fac[MAX], finv[MAX], inv[MAX];
 
void init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
int comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

signed main() {
    int x, y;
    cin>>x>>y;
    if ((x + y) % 3 != 0) {
        cout<<0<<endl;
        return 0;
    }
    int a, b;
    a = (2 * x - y) / 3;
    b = (2 * y - x) / 3;
    init();
    cout<<comb(a + b, a)<<endl;
}