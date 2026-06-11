#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

#define INF (1LL << 60)
#define MOD 1000000007LL
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


ll modpow(ll a, ll n, ll m)
{
    if(n == 0) return 1;
    ll t = modpow(a, n >> 1, m);
    t = t * t % m;
    if(n & 1) t = t * a % m;
    return t; 
}

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;

    vec inv(200010, 0);
    inv[1] = 1;
    REP(i,2,200010) inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;

    ll nCa = 1, nCb = 1, c;
    REP(i,1,a+1) nCa = (nCa * (n-i+1) % MOD) * inv[i] % MOD;
    REP(i,1,b+1) nCb = (nCb * (n-i+1) % MOD) * inv[i] % MOD;
    c = ((modpow(2, n, MOD) - 1 - nCa - nCb) % MOD + MOD) % MOD;
    PR(c); 

    return 0;
}

/*

nC1 + ... + nCn - nCa - nCb
= 2^n - 1 - nCa - nCb

*/