#include<bits/stdc++.h>
using namespace std;
#define ms(x,y) memset(x, y, sizeof(x))
#define lowbit(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

const LL MOD = 1e9+7;

LL qpow(LL a, LL b) {
    LL ret = 1;
    while(b) {
        if(b & 1) (ret *= a) %= MOD;
        (a *= a) %= MOD;
        b >>= 1;
    }
    return ret;
}

void run_case() {
    LL n;
    cin >> n;
    if(n == 1) {
        cout << 0;
        return;
    }
    cout << ((qpow(10, n) - qpow(9,n) - qpow(9, n) + qpow(8, n))%MOD+MOD)%MOD;
    
}


int main() {
    //freopen("input", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(0);
    cout.flags(ios::fixed);cout.precision(6);
    //int t; cin >> t;
    //while(t--)
    run_case();
    cout.flush();
    return 0;
}