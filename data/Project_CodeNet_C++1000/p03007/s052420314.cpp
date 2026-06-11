#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define REPS(i, m, n) for (int i = (m); i <= (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define reps(i, n) for (int i = 0; i <= (int)(n); i++)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define rreps(i, x) for (int i = (int)(x); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> P;
const int inf = INT_MAX;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;
const double EPS = 1e-10;
const double PI = acos(-1.0);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val) { fill( (T*)array, (T*)(array+N), val ); }

int N;
vector<ll> A;

void solve() {
    vector<ll> p, m;
    rep(i, N) {
        if (A[i] >= 0) p.pb(A[i]);
        else m.pb(A[i]);
    }
    sort(rall(p));
    sort(all(m));
    if (m.empty()) m.pb(p.back()), p.pop_back();
    if (p.empty()) p.pb(m.back()), m.pop_back();

    vector<pair<ll, ll>> res;
    ll cur = m[0];
    rep(i, p.size()-1) {
        res.pb({cur, p[i]});
        cur -= p[i];
    }
    res.pb({p.back(), cur});
    cur = p.back() - cur;

    REP(i, 1, m.size()) {
        res.pb({cur, m[i]});
        cur -= m[i];
    }

    cout << cur << endl;
    for (pair<ll, ll> x : res) {
        cout << x.fi << ' ' << x.se << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];
    solve();
    return 0;
}
