#include <bits/stdc++.h>
#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vl;
const ll MOD = round(1e9+7);

/*nCk (mod MOD)の計算 BEGIN*/
//faccal -> n!, k!^(MOD-2)の計算(初期化)
//comb -> nCk (mod MOD)の計算
ll mlpow(ll x, ll p) { //x^p(long long)%MOD
    ll tmp = 1;
    if(p == 0) return 1;
    //繰り返し二乗法
    while(p != 0) {
        if(p & 1) tmp = tmp*x % MOD;
        x = x*x % MOD;
        p = p >> 1;
    }
    return tmp;
}

int facnum = 700000;
vl fac(facnum);   //n!
vl facM2(facnum);  //k!^(MOD-2)

void faccal(ll up) {
    fac[0] = 1;
    facM2[0] = 1;
    for(ll i = 0; i<up+1; i++){
        fac[i+1] = fac[i]*(i+1) % MOD; // n!(mod M)
        facM2[i+1] = facM2[i]*mlpow(i+1, MOD-2) % MOD; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
}

ll comb(ll n, ll k) {
    if(n == 0 && k == 0) return 1;
    if(n < k || n < 0) return 0;
    if(k > n-k) k = n-k;
    ll tmp = facM2[n-k]*facM2[k] % MOD;
    return tmp*fac[n] % MOD;  //nCk = n!*(k!)^(M-2)*((n-k)!)^(M-2)
}
/*nCk (mod MOD)の計算 END*/

int main() {
    int X,Y; cin >> X >> Y;
    int a = (2*Y-X)/3;
    int b = (2*X-Y)/3;
    if(((2*Y-X)%3 != 0) || ((2*X-Y)%3 != 0)
    || a < 0 || b < 0) {
        cout << 0 << endl;
        return 0;
    }

    faccal(a+b+1);

    cout << comb(a+b, a) << endl;
    return 0;
}
