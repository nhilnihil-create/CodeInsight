#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

const int maxn = 2e6+5;
const LL MOD = 1e9+7;
LL inv[maxn], f[maxn], invf[maxn];

void init() {
    inv[1] = 1;
    for(int i = 2; i < maxn; ++i)
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    f[0] = invf[0] = 1;
    for(int i = 1; i < maxn; ++i) {
        f[i] = f[i-1] * 1LL * i % MOD;
        invf[i] = invf[i-1] * inv[i] % MOD;
    }
}

LL comb(int a, int b) {
    if(b < 0 || b > a) return 0;
    return f[a]*invf[a-b]%MOD*invf[b]%MOD;
}

void run_case() {
    LL n, m;
    init();
    cin >> n >> m;
    if((n+m)%3) cout << "0\n";
    else {
        
        cout << (comb((n+m)/3, (2*n-m)/3) + MOD) % MOD;
    }
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cout.flags(ios::fixed);cout.precision(9);
    //int t; cin >> t;
    //while(t--)
    run_case();
    cout.flush();
    return 0;
}
