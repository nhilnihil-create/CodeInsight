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

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vec a(N);
    REP(i,0,N) {
        cin >> a[i];
        a[i] /= 2;
    }

    vec C(N, 0);
    ll c, d = 0;
    bool f, g;
    while(true) {
        f = true;
        REP(i,0,N) {
            if(a[i] % 2 == 0) {
                f = false;
                a[i] /= 2;
                ++C[i];
            }
        }
        g = true;
        c = C[0];
        REP(i,0,N) {
            if(c != C[i]) g = false;
        }
        if(f) break;
    }

    if(f && g) {
        ll L = 1;
        REP(i,0,N) L = lcm(L, a[i]);
        L *= (1 << c);
        PR((M/L+1)/2);
    }
    else PR(0);
    

    return 0;
}

/*



*/