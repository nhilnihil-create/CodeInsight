#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

ll mod = 1000000007;

ll kai(ll x){
    if (x == 0) return 1;
    ll a = kai(x/2);
    a *= a;
    a = a % mod;
    if (x % 2 == 1) a *= 2;
    a = a % mod;
    return a;
}

ll kain(ll A, ll n){
    if (n == 0) return 1;
    ll a = kain(A, n / 2);
    a *= a;
    a = a % mod;
    if (n % 2 == 1) a *= A;
    a = a % mod;
    return a;
}

int main() {
    ll n, a, b; cin >> n >> a >> b;

    //2^n -1 mod を求める
    ll X = kai(n);

    //nCa mod を求める

    ll aa = 1;
    for (int i = 1; i <= a; i++){
        aa *= i;
        aa = aa % mod;
    }
    ll bb = 1;
    for (int i = 1; i <= b; i++){
        bb *= i;
        bb = bb % mod;
    }
    ll nna = 1;
    for (int i = 0; i < a ; i++){
        nna *= n - i;
        nna = nna % mod;
    }
    ll nnb = 1;
    for (int i = 0; i < b ; i++){
        nnb *= n - i;
        nnb = nnb % mod;
    }
    
    ll A = (nna * kain(aa, mod-2)) % mod;
    ll B = (nnb * kain(bb, mod-2)) % mod;

    ll ans = X - 1 - A - B;
    while(ans < 0){
        ans += mod;
    }

    cout << ans << endl;

}