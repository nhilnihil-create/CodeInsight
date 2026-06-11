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


void modcomb(vec &c, ll n, ll k, ll m)
{
    vec inv(k+1, 0);
    inv[1] = 1;
    c[0] = 1; c[1] = n;
    REP(i,2,k+1) {
        inv[i] = m - inv[m%i] * (m / i) % m;
        c[i] = (((c[i-1] * (n - i + 1)) % m) * inv[i]) % m;
    }
}


int main()
{
    ll X, Y;
    cin >> X >> Y;

    ll k = 2 * Y - X;
    ll l = 2 * X - Y;
    ll cnt = 0;
    if(k >= 0 && k % 3 == 0 && l >= 0 && l % 3 == 0) {
        k /= 3; l /= 3;
        ll n = k + l;
        k = MIN(k,l);
        vec C(k+1);
        modcomb(C, n, k, MOD);
        cnt = C[k];
    }
    PR(cnt);

    return 0;
}

/*



*/