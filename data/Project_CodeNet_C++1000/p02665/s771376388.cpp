#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define ALL(name) name.begin(),name.end()
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 0
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 100010

int N;
vector<int> A;

int solve() {
    // 下から取れる葉の min,max を測る
    vector< pair<int, int> > lim(N + 1);
    pair<int, int> cur = {A[N], A[N]};
    lim[N] = cur;
    for(int i = N - 1; i >= 0; --i) {
        // 最小
        lim[i].first = (lim[i+1].first + 1) / 2 + A[i];
        // 最大
        lim[i].second = (lim[i+1].second) + A[i];
        DBG("lim[%lld]: (%lld, %lld)\n", i, lim[i].first, lim[i].second);
    }
    if(lim[0].first > 1) {
        return -1;
    }

    int ret = 0;
    int border = 1;
    REP(i, N + 1) {
        if(i > 0) { border = border * 2; }
        DBG("i: %lld border: %lld lim[i]: (%lld, %lld)\n", i, border, lim[i].first, lim[i].second);
        int add = min(border, lim[i].second);
        DBG("add: %lld\n", add);
        ret += add;
        border = add - A[i];
    }

    return ret;
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N + 1);
    REP(i, N + 1) {
        cin >> A[i];
    }

    int ans = solve();
    printf("%lld\n", ans);

    return 0;
}
