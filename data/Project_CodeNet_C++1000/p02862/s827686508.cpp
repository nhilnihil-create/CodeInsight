#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

#define MOD 1000000007

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<P> vpi;
typedef pair<ll,ll> Pl;
typedef vector<ll> vl;
typedef vector<Pl> vpl;


/*nCk (mod MOD)の計算 BEGIN*/
//faccal -> n!, k!^(MOD-2)の計算(初期化)
//comb -> nCk (mod MOD)の計算
ll mlpow(ll x, ll p) { //x^p(long long)%MOD
    ll tmp = 1;
    if(p == 0) return 1;
    while(p != 0) {
        if(p & 1) tmp = tmp*x % MOD;
        x = x*x % MOD;
        p = p >> 1;
    }
    return tmp;
}

int facnum = 2000005;
vl fac(facnum);   //n!
vl facM2(facnum);  //k!^(MOD-2)

void faccal(ll up) {
    fac[0] = 1;
    facM2[0] = 1;
    for(ll i = 0; i < up+1; i++){
        fac[i+1] = fac[i]*(i+1) % MOD; // n!(mod M)
        facM2[i+1] = facM2[i]*mlpow(i+1, MOD-2) % MOD; // k!^{M-2} (mod M) ←累乗にmpowを採用
    }
}

ll comb(ll n, ll k) {
    if(n == 0 && k == 0) return 1;
    if(n < k || n < 0) return 0;
    ll tmp = facM2[n-k]*facM2[k] % MOD;
    return tmp*fac[n] % MOD;  //nCk = n!*(k!)^(M-2)*((n-k)!)^(M-2)
}
/*nCk (mod MOD)の計算 END*/

int main() {
    int X, Y;
    cin >> X >> Y;

    ll ans = 0;
    int m = (2*X - Y)/3, n = (2*Y - X)/3;
    int mr = (2*X - Y)%3, nr = (2*Y - X)%3;
    if(mr == 0 && nr == 0 && m >= 0 && n >= 0) {
        faccal(m+n);
        ans = comb(m+n, m);
    }

    cout << ans << "\n";
    return 0;
}
