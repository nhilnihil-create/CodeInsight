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
#define FOR(i,m,n) for (int i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

const int MAX = 310;
const ll INF = 1e18-1;

ll N, K, H[MAX];
ll dp[MAX][MAX]; // dp[i][k] : i個目まででk個を使ったときの最小値、ただしi個目は使っている

ll solve() {
    REP (i, MAX) FOR (j, 1, MAX) dp[i][j] = INF;
    REP (i, N) dp[i][1] = H[i];
    FOR (i, 1, N) {
        FOR (k, 2, N-K+1) {
            REP (l, i)
                dp[i][k] = min(dp[i][k], dp[l][k-1]+max(0ll, H[i]-H[l]));
        }
    }
    ll ans = INF;
    REP (i, N) ans = min(ans, dp[i][N-K]);
    return ans;
}

int main() {
    cin >> N >> K;
    REP (i, N) cin >> H[i];
    cout << solve() << endl;
}