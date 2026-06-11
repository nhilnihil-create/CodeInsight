#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

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
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back


ll modpow(ll a, ll n, ll m)
{
    if(n == 0) return 1;
    ll t = modpow(a, n >> 1, m);
    t = t * t % m;
    if(n & 1) t = t * a % m;
    return t; 
}

ll modinv(ll a, ll m)
{
    return modpow(a, m - 2, m);
}

int main()
{
    ll N;
    cin >> N;
    vec A(N);
    REP(i,0,N) cin >> A[i];

    vec C(60, 0);
    REP(i,0,N) {
        REP(j,0,60) C[j] += ((A[i] >> j) & 1);
    }

    ll sum = 0;
    REP(i,0,N) {
        REP(j,0,60) {
            if((A[i] >> j) & 1) sum = (sum + ((1LL << j) % MOD) * (N - C[j])) % MOD;
            else sum = (sum + ((1LL << j) % MOD) * C[j]) % MOD;
        }
    }
    PR((sum*modinv(2,MOD))%MOD);

    return 0;
}

/*



*/