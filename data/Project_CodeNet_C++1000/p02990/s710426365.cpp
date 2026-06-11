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

ll gcd(ll a, ll b){ //aとbの最大公約数を求める
    if(a < b) swap(a, b);
    if(b <= 0) return -1;
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b){ //aとbの最小公倍数を求める(gcd要)
    return (a/gcd(a,b)*b);
}

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

int facnum = 2005;
vl fac(facnum);   //n!
vl facM2(facnum);  //k!^(MOD-2)

void faccal(void) {
    fac[0] = 1;
    facM2[0] = 1;
    for(ll i = 0; i<2000; i++){
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
    int N, K;
    cin >> N >> K;

    faccal();


    rep1(i,K){
        ll ans = comb(K-1,i-1)*comb(N-K+1,i);
        ans %= MOD;
        cout << ans << endl;
    }
    return 0;
}
