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
    ll X, Y;
    cin >> X >> Y;
    
    ll A = Y * 2 - X, B = X * 2 - Y;
    if(A >= 0 && B >= 0 && A % 3 == 0 && B % 3 == 0) {
        A /= 3; B /= 3;
        vec C = modcomb(A + B, MIN(A,B), MOD);
        PR(C[MIN(A,B)]);
    }
    else PR(0);

    return 0;
}

/*



*/