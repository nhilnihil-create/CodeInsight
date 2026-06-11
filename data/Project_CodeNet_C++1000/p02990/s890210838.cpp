#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)

static const int MAXV = 510000;
static const int mod = 1000000007;
long long fac[MAXV], finv[MAXV], inv[MAXV];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAXV; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
int main(){
    int n, k; sc(n), sc(k);
    COMinit();
    ll tmp1, tmp2;
    rep(i, 1, k+1){
        tmp1 = COM(k-1, i - 1);
        tmp2 = COM(n - k + 1, i);
        cout << tmp1 * tmp2 % mod << endl;
    }
    return 0;
}