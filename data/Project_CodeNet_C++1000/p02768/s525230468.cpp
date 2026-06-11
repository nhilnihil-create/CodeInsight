#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

const ll mod = 1e9 + 7;

int modPow(ll a, ll n, ll p) {
    if (n == 1) return a % p;
    if (n % 2 == 1) return a * modPow(a, n - 1, p) % p;
    ll t = modPow(a, n / 2, p);
    return t * t % p;
}



int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll x = modPow(2, n, mod);
    ll yf = 1;
    for (ll i = 1; i <= a; ++i) {
        yf *= i;
        yf %= mod;
    }
    yf = modPow(yf, mod - 2, mod) % mod;
    ll yg = 1;
    for (ll i = n; i >= n - a + 1; --i) {
        yg *= i;
        yg %= mod;
    }
    ll zf = 1;
    for (ll i = 1; i <= b; ++i) {
        zf *= i;
        zf %= mod;
    }
    zf = modPow(zf, mod - 2, mod) % mod;
    ll zg = 1;
    for (ll i = n; i >= n - b + 1; --i) {
        zg *= i;
        zg %= mod;
    }
    ll y = yf * yg % mod;
    ll z = zf * zg % mod;
    ll ans = (x - y - z - 1 + 10 * mod) % mod;
    cout << ans << endl;
}