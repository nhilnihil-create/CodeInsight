
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e15;
static const ll mod = 1e9+7;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}

int main() {
    ll n, k, s;
    cin >> n >> k >> s;
    const ll u = 1000000000;
    if (s == u) {
        for (int i = 0; i < k; i++) {
            cout << s << " ";            
        }
        for (int i = k; i < n; i++) {
            cout << 1 << " ";
        }
        cout << endl;
        return 0;
    }
    for (int i = 0; i < k; i++) {
        cout << s << " ";
    }
    for (int i = k; i < n; i++) {
        cout << s + 1 << " ";
    }
    cout << endl;
    return 0;
}
