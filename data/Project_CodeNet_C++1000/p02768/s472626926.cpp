#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define INF (1LL << 60)
#define MOD 1000000007

#define REP(i,m,n) for(ll (i)=(m),i##_len=(n);(i)<(i##_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define _PR(x) cout << (x) << endl
#define _PS(x) cout << (x) << " "
#define SZ(x) ((int)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define pb push_back

#define M 210000

vector<ll> fac(M), finv(M), inv(M);

ll pow2mod(ll n)
{
    ll p = 1;

    REP(i,0,n/10) p = p * 1024 % MOD;
    REP(i,0,n%10) p = p * 2 % MOD;

    return p;
}

void combinit()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    REP(i,2,M) {
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

    combinit();

    ll res;
    res = (pow2mod(n) - 1 - combmod(n, a) - combmod(n, b)) % MOD;
    if (res < 0) res += MOD;

    _PR(res);

    return 0;
}

/*



*/