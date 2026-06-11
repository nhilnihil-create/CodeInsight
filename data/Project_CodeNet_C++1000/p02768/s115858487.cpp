#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ASC(x) sort(ALL((x)))
#define DESC(x) sort(ALL((x)),greater<ll>())
#define pb push_back


vec fac(210000), finv(210000), inv(210000);

ll modpow(ll a, ll n, ll m)
{
    if(n == 0) return 1;
    ll t = modpow(a, n >> 1, m);
    t = t * t % m;
    if(n & 1) t = t * a % m;
    return t; 
}

void combinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    REP(i,2,210000) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
 
ll combmod(ll n, ll r)
{
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    ll c = 1;
    REP(i,0,r) c = c * (n-i) % MOD;
    c = c * finv[r] % MOD;
    return c;
}

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;

//    vec inv(200010, 0);
//    inv[1] = 1;
//    REP(i,2,200010) inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;

    combinit();

    ll nCa = 1, nCb = 1, c, f = 1;
    REP(i,1,a+1) nCa = (nCa * (n-i+1) % MOD);
    REP(i,2,a+1) f = f * inv[i] % MOD; nCa = nCa * f % MOD;
    REP(i,1,b+1) nCb = (nCb * (n-i+1) % MOD);
    f = 1;
    REP(i,2,b+1) f = f * inv[i] % MOD; nCb = nCb * f % MOD;
    c = (modpow(2, n, MOD) - 1- nCa - nCb) % MOD;
    c = (c < 0) ? c + MOD : c;
    PR(c); 

    return 0;
}

/*

nC1 + ... + nCn - nCa - nCb
= 2^n - 1 - nCa - nCb

*/