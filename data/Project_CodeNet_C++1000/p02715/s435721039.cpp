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
#define REV(x) reverse(ALL((x)))
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
    ll N, K;
    cin >> N >> K;

    vec C(K+1, 0);
    for(ll i=K; i>=1; --i) {
        C[i] = modpow(K/i, N, MOD);
        for(ll j=i*2; j<=K; j+=i) {
            C[i] = (C[i] - C[j]) % MOD;
        }
    }

    ll sum = 0;
    REP(i,1,K+1) {
        sum = (sum + (i * C[i]) % MOD) % MOD;
    }
    sum = (sum < 0 ? sum + MOD : sum);
    PR(sum);

    return 0;
}

/*



*/