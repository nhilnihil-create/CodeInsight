#include <bits/stdc++.h>

using namespace std;
#define local
#ifdef local

template<class T>
void _E(T x) { cerr << x; }

void _E(double x) { cerr << fixed << setprecision(6) << x; }

void _E(string s) { cerr << "\"" << s << "\""; }

template<class A, class B>
void _E(pair<A, B> x) {
    cerr << '(';
    _E(x.first);
    cerr << ", ";
    _E(x.second);
    cerr << ")";
}

template<class T>
void _E(vector<T> x) {
    cerr << "[";
    for (auto it = x.begin(); it != x.end(); ++it) {
        if (it != x.begin()) cerr << ", ";
        _E(*it);
    }
    cerr << "]";
}

void ERR() {}

template<class A, class... B>
void ERR(A x, B... y) {
    _E(x);
    cerr << (sizeof...(y) ? ", " : " ");
    ERR(y...);
}

#define debug(x...) do { cerr << "{ "#x" } -> { "; ERR(x); cerr << "}" << endl; } while(false)
#else
#define debug(...) 114514.1919810
#endif
#define _rep(n, a, b) for (ll n = (a); n <= (b); ++n)
#define _rev(n, a, b) for (ll n = (a); n >= (b); --n)
#define _for(n, a, b) for (ll n = (a); n < (b); ++n)
#define _rof(n, a, b) for (ll n = (a); n > (b); --n)
#define oo 0x3f3f3f3f3f3f3f3f
#define ll long long
#define db long double
#define eps 1e-3
#define bin(x) cerr << bitset<10>(x) << endl
#define what_is(x) cerr << #x << " is " << x << endl
#define met(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>
#define pdd pair<db, db>
#define endl "\n"
const ll mod = 1e9 + 7;
const ll maxn = 2e3 + 10;
const db pi = acos(-1.0);

ll qpow(ll a, ll b) {
    ll ret = 1;
    for (; b; a = a * a % mod, b >>= 1) {
        if (b & 1) {
            ret = ret * a % mod;
        }
    }
    return ret;
}

vector<ll> f(maxn), invf(maxn);

ll inv(ll a) {
    return qpow(a, mod - 2);
}

void prework() {
    f[0] = 1;
    _rep(i, 1, maxn - 1) {
        f[i] = f[i - 1] * i % mod;
    }
    invf[maxn - 1] = qpow(f[maxn - 1], mod - 2);
    for (ll i = maxn - 2; i >= 0; i--) {
        invf[i] = invf[i + 1] * (i + 1) % mod;
    }
}

ll C(ll n, ll m) {
    if (n > m || m < 0)return 0;
    if (n == 0 || m == n) return 1;
    ll res = (f[m] * invf[m - n] % mod * invf[n]) % mod;
    return res;
}

vector<ll> r, c;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll h, w, m;
    cin >> h >> w >> m;
    r.resize(h + 1);
    c.resize(w + 1);
    map<pii, ll> cc;
    vector<pii > q;
    _rep(i, 1, m) {
        ll x, y;
        cin >> x >> y;
        r[x]++;
        c[y]++;
        cc[make_pair(x, y)] = 1;
        q.push_back(make_pair(x, y));
    }
    ll mxh = 0, mxw = 0;
    _rep(i, 1, h) {
        if (mxh < r[i]) {
            mxh = r[i];
        }
    }
    _rep(i, 1, w) {
        if (mxw < c[i]) {
            mxw = c[i];
        }
    }
    vector<ll> mxhh, mxcc;
    _rep(i, 1, h) {
        if (r[i] == mxh) {
            mxhh.push_back(i);
        }
    }
    _rep(i, 1, w) {
        if (mxw == c[i]) {
            mxcc.push_back(i);
        }
    }

//    ll res = 0;
//    for (auto x:mxhh) {
//        for (auto y:mxcc) {
//            debug(cc[make_pair(x, y)]);
//            res = max(res, (cc[make_pair(x, y)] ? r[x] + c[y] - 1 : r[x] + c[y]));
//        }
//    }
    int cnt = 0;
    for (auto i:q) {
        if (r[i.first] == mxh && c[i.second] == mxw)cnt++;
    }
    cout << (cnt == mxcc.size() * mxhh.size() ? mxh + mxw - 1 : mxh + mxw) << endl;
}