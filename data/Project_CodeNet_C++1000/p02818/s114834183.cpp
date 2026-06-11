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
static inline void chmin(T & ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T & ref, const T value) {
    if (ref < value) ref = value;
}

const ll mod = 1000000007;

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    if (k <= a) {
        cout << a - k << " " << b << endl;
    }
    else {
        cout << 0 << " " << max(0LL, b - (k-a)) << endl;
    }
    return 0;
}

