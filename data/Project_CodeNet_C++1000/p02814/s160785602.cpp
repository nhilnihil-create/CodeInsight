#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using vec_b = vector<bool>;
using vec_str = vector<string>;

#define INF (1LL << 60)
#define MOD 1000000007

#define REP(i,m,n) for(ll (i)=(m),i##_len=(n);(i)<(i##_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define _PR(x) cout << (x) << endl
#define _PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
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
    REP(i,0,N) cin >> a[i];

    vec_b F(N);
    bool all_odd, all_even;
    ll d = -1;
    while(true) {
        if(a[0] % 2 == 0) {
            all_odd = false;
            all_even = true;
        }
        else {
            all_odd = true;
            all_even = false;
        }
        REP(i,1,N) {
            if(a[i] % 2 == 0 && all_odd) {
                all_odd = false;
                break;
            }
            else if(a[i] % 2 == 1 && all_even) {
                all_even = false;
                break;
            }
        }
        if(!all_even) break;
        REP(i,0,N) a[i] >>= 1;
        ++d;
    }
    if(!all_odd && !all_even) _PR(0);
    else {
        ll L = a[0];
        REP(i,1,N) L = lcm(L, a[i]);
        L *= (1 << d);
        _PR(M/L-M/(L*2));
    }

    return 0;
}

/*



*/