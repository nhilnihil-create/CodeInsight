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

vec modcomb(ll n, ll k, ll m)
{
    vec c(k+1, 0), inv(k+1, 0);
    inv[1] = 1;
    c[0] = 1; c[1] = n;
    REP(i,2,k+1) {
        inv[i] = m - inv[m%i] * (m / i) % m;
        c[i] = (((c[i-1] * (n - i + 1)) % m) * inv[i]) % m;
    }
    return c;
}


int main()
{
    ll N, A, B;
    cin >> N >> A >> B;

    vec C = modcomb(N, MAX(A, B), MOD);
    PR(((modpow(2,N,MOD)-(C[A]+C[B]+1))%MOD+MOD)%MOD);

    return 0;
}

/*



*/