
    #include <bits/stdc++.h>

    #define M_PI       3.14159265358979323846   // pi

    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    typedef pair<ll, ll> P;
    typedef tuple<ll, ll, ll> t3;
    typedef tuple<ll, ll, ll, ll> t4;

    #define rep(a,n) for(ll a = 0;a < n;a++)

    static const ll INF = 1e15;

    template<typename T>
    static inline void chmin(T& ref, const T  value) {
        if (ref > value) ref = value;
    }

    template<typename T>
    static inline void chmax(T& ref, const T value) {
        if (ref < value) ref = value;
    }

    ll gcd(ll a, ll b) { while (b) a %= b, swap(a, b); return abs(a); }

    ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

    int main() {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll cd = lcm(c, d);
        ll x1 = b / c - (a - 1) / c;
        ll x2 = b / d - (a - 1) / d;
        ll x3 = b / cd - (a - 1) / cd;
        ll ans = x1 + x2 - x3;
        cout << b - (a-1) - ans << endl;
        return 0;
    }
