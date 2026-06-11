#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define ALL(v) v.begin(), v.end()

const int MAX = 5010;

int K, Q;
ll D[MAX];

ll solve(ll N, ll X, ll M) {
    ll all = N - 1;
    ll a_n = X % M;
    ll sm = 0;
    REP (i, K) {
        ll n = (N-1) / K;
        if (i < (N-1) % K) n++;
        a_n += (D[i] % M) * n;
        if (D[i] % M == 0) sm += n;
    }
    all -= sm + a_n / M;
    return all;
}

int main() {
    cin >> K >> Q;
    REP (i, K) cin >> D[i];
    REP (i, Q) {
        int n, x, m;
        cin >> n >> x >> m;
        cout << solve(n, x, m) << endl;
    };
}