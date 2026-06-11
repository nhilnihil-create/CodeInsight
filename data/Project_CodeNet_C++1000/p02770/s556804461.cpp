#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

template<typename T1,typename T2> inline void chmin(T1 &a, T2 b){ if(a > b) a = b; }
template<typename T1,typename T2> inline void chmax(T1 &a, T2 b){ if(a < b) a = b; }

#define REP(i,n) for(int i=0;i<n;++i)
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
const int MAX_N = 100010;

int K, Q;
vector<int> D;

int solve() {
    int n, x, m;
    cin >> n >> x >> m;
    x %= m;
    vector<int> DM(K);
    REP(i, K) {
        DM[i] = D[i] % m;
    }

    // ai -> ai+1 で ai == ai+1 のケース
    // d が 0 の時のみ
    int zero_cnt = 0;
    REP(i, K) {
        if(DM[i] == 0) { zero_cnt++; } 
    }
    int zero_case = (n - 1) / K * zero_cnt;
    for(int i = 0; i < ((n - 1) % K); ++i) {
        if(DM[i] == 0) { zero_case++; }
    }
    //DBG("zero_case: %lld\n", zero_case);

    // ai -> ai+1 で ai > ai+1 のケース
    // / m したときの値が +1 されている
    int dm_sum = 0;
    REP(i, K) {
        dm_sum += DM[i];
    }
    int lb = x / m;
    int div = (n - 1) / K;
    int ub = x + dm_sum * div;
    for(int i = 0; i < ((n - 1) % K); ++i) {
        ub += DM[i];
    }
    ub /= m;
    int down_case = ub - lb;

    int ret = n - 1 - zero_case - down_case;

    return ret;
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> K >> Q;
    D.resize(K);
    REP(i, K) {
        cin >> D[i];
    }

    REP(i, Q) {
        int ans = solve();
        printf("%lld\n", ans);
    }

    return 0;
}
