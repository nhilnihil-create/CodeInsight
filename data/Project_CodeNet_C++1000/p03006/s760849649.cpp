#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


#define rep(i,n) for(ll (i)=0; (i)<(ll)(n); (i)++)
#define frep(i,m,n) for(ll (i)=(m); (i)<=(ll)(n); (i)++)
#define rrep(i,n) for(ll (i)=(n)-1; (i)>-1; (i)--)
#define frrep(i,m,n) for(ll (i)=(n); (i)>(ll)(m); (i)--)
#define ALL(x) (x).begin(), (x).end()
#define MP(x, y) make_pair(x, y)

const ll INF = 100100100100100100;
const ll MOD = 1000000007;

// get abs
ll my_abs(ll a);
// a^n
ll a_n(ll a, ll n);
// get gcd
ll my_gcd(ll a, ll b);
// a^(-1) % MOD 
ll inv(ll a);
// (a+b+c)%MOD
ll madd(ll a, ll b, ll c);
// (a-b)%MOD
ll msub(ll a, ll b);
// (a*b*c)%MOD
ll mtime(ll a, ll b, ll c);


int main() {
    ll n; cin >> n;
    vector<P> p(n);
    map<P, ll> m;
    rep(i, n) {
        ll x, y; cin >> x >> y;
        p[i] = MP(x, y);
    }
    frep(i, 0, n-2) {
        frep(j, i+1, n-1) {
            ll x = p[i].first - p[j].first;
            ll y = p[i].second - p[j].second;
            if(x < 0 && y < 0) {
                x *= -1;
                y *= -1;
            }
            if(x > 0 && y < 0) {
                x *= -1;
                y *= -1;
            }
            if(y == 0) x = my_abs(x);
            if(x == 0) y = my_abs(y);
            if(m.count(MP(x, y))) {
                m[MP(x, y)]++;
            }
            else {
                m[MP(x, y)] = 1;
            }
        }
    }
    ll a = 0;
    for(auto p: m) {
        auto value = p.second;
        if(a < value) a = value;
    }

    cout << n-a << endl;

    return 0;
}

ll my_abs(ll a) {
    if(a >= 0) return a;
    else return -1 *a;
}

ll a_n(ll a, ll n) { 
    if(n == 0) return 1;
    
    ll ret = a, count = 1;
    while(count * 2 < n) {
        ret *= ret;
        count *= 2;
    }
    if(count == n) return ret;
    else return (ret * a_n(a, n-count));
}

ll my_gcd(ll a, ll b) {
    if(b == 0) return a;
    return my_gcd(b, a%b);
}

ll inv(ll a) {
    return a_n(a, MOD-2);
}

ll madd(ll a, ll b, ll c) {
    ll ret = (a+b) % MOD;
    return (ret+c) % MOD;
}

ll msub(ll a, ll b) {
    if(a < b) return (a-b+MOD) % MOD;
    else return (a-b) % MOD;
}

ll mtime(ll a, ll b, ll c) {
    ll ret = (a*b) % MOD;
    return (ret*c) % MOD;
}
