#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define ALL(name) name.begin(),name.end()
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 100010
#define SUBMIT

ll T1, T2, A1, A2, B1, B2;

ll solve() {
    ll X = T1 * A1 - T1 * B1;
    ll Y = T2 * A2 - T2 * B2;

    if(X + Y == 0) { return -1; }

    if((X < 0 && Y < 0) || (X > 0 && Y > 0) || Y == 0) { return 0; }

    if(X == 0) { return 1; }

    X = abs(X);
    Y = abs(Y);
    if(X > Y) { return 0; }

    ll ret = X / (Y - X) * 2;
    if(X % (Y - X) != 0) { ret++; }
    return ret;
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

    ll ans = solve();
    if(ans == -1) {
        printf("infinity\n");
        return 0;
    }
    printf("%lld\n", ans);

    return 0;
}