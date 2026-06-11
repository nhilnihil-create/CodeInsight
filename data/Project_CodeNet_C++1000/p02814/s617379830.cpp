#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

constexpr ll mod = 1000000007;

ll gcd(ll a, ll b) { while (b) a %= b, swap(a, b); return abs(a); }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> vs(n);
    vector<ll> vs2(n);
    rep(i, n) {
        cin >> vs[i];
        vs2[i] = vs[i] / 2;
    }
    ll mult = 1;
    rep(i, n) {
        mult = lcm(mult, vs2[i]);
    }
    ll ok = true;
    rep(i, n) {
        auto div = mult / vs2[i];
        if (div % 2 == 0) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << (m / mult + 1) / 2 << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}

