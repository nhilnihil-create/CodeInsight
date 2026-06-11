#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define INF_LL 1000000000000000000LL
#define INF 200000000
#define MOD 998244353
#define ll long long
#define all(x) x.begin(), x.end()
#define REP(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
// typedef float double;
// typedef priority_queue prique;
typedef pair<ll, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
typedef vector<ll> vl;
typedef vector<vi> matrix;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int sign[2] = {1, -1};
template <class T> bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}

ll modpow(ll a, ll b, ll m) {
    if(b == 0)
        return 1;
    ll t = modpow(a, b / 2, m);
    if(b & 1) {
        return (t * t % m) * a % m;
    } else {
        return t * t % m;
    }
}

struct edge {
    int to;
    ll cost;
    edge(int t, ll c) { to = t, cost = c; }
};

int main() {
    int n, q;
    cin >> n >> q;
    dsu d(n);
    rep(i, q) {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0) {
            d.merge(u, v);
        } else {
            if(d.same(u, v)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
}
