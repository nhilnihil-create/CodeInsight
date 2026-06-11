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
#define FORI(i,v) for (auto i = v.begin(); i != v.end(); i++)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)
#define YES(b) cout << ((b) ? "YES" : "NO") << endl
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl

const int MAX = 2e5+10;

ll N, K;
ll A[MAX];

void solve() {
    REP (k, K) {
        vi imos(N+1);
        ll mn = MAX;
        REP (i, N) {
            CHMIN(mn, A[i]);
            imos[max(0ll, i-A[i])]++;
            imos[min(N, i+A[i]+1)]--;
        }
        REP (i, N-1) imos[i+1] += imos[i];
        REP (i, N) A[i] = imos[i];
        if (mn == N) return;
    }
}

int main() {
    cout << fixed << setprecision(15);
    cin >> N >> K;
    REP (i, N) cin >> A[i];
    solve();
    REP (i, N) cout << A[i] << " ";
    cout << endl;
}