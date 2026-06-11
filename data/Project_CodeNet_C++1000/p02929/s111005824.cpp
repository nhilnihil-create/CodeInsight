#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

const int MAX_N = 2e5;
ll fac[MAX_N+1], ifac[MAX_N+1], inv[MAX_N+1];

//mpow(x,n)で(x^n)をO(log(n))で計算
ll mpow(ll x, ll n){
    ll res = 1, now = x;
    while(n > 0){
        if(n%2 == 1) res *= now, res %= MOD;
        now *= now, now %= MOD;
        n /= 2;
    }
    return res;
}

//setcomb()でfac,ifac,invを全て計算
void setcomb(){
    rep2(i, 1, MAX_N){
        inv[i] = mpow(i, MOD-2);
    }
    //i!とi!の逆元
    fac[0] = 1, ifac[0] = 1;
    rep2(i, 1, MAX_N){
        fac[i] = (fac[i-1]*i) % MOD;
        ifac[i] = (ifac[i-1]*inv[i]) % MOD;
    }
}

//comb(n, k)でnCk
ll comb(int n, int k){
    ll c = fac[n];
    c *= ifac[n-k], c %= MOD;
    c *= ifac[k], c %= MOD;
    return c;
}

//perm(n, k)でnPk
ll perm(int n, int k){
    return(fac[n]*ifac[n-k])%MOD;
}

int main(){
    int N;
    string S;
    cin >> N >> S;
    vector<int> L, R;
    rep(i, 2*N){
        int A = (S[i] == 'B') + (2*N-i);
        //cout << A << endl;
        if(A%2) L.pb(i);
        else R.pb(i);
    }
    if(L.size() != R.size()){
        cout << 0 << endl;
        return 0;
    }
    setcomb();
    ll ans = fac[N];
    rep(i, N){
        int j = lower_bound(L.begin(), L.end(), R[i]) - L.begin();
        //cout << j << endl;
        if(j <= i){
            cout << 0 << endl;
            return 0;
        }
        else ans *= (j-i), ans %= MOD;
    }
    cout << ans << endl;
}