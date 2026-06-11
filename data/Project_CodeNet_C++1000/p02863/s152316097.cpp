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
const int MAX_N = 3010;

int N, T;
vector<int> A, B;
int dp[MAX_N][MAX_N][2];

// i 番目の料理を見ていて、現在のコストは j、
// 最後に食べるものを選定済みなら k = 1, そうでないなら k = 0
int dfs(int i, int j, int k) {
    if(i >= N) {
        return 0;
    }

    int& ret = dp[i][j][k];
    if(~ret) { return ret; }

    // 食べない場合
    ret = dfs(i + 1, j, k);

    // 食べる場合
    if(j + A[i] < T) {
        chmax(ret, dfs(i+1, j + A[i], k) + B[i]);
    }

    // これを最後に選ぶ場合
    if(k == 0) {
        chmax(ret, dfs(i+1, j, 1) + B[i]);
    }

    return ret;
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> T;
    A.resize(N);
    B.resize(N);
    REP(i, N) {
        cin >> A[i] >> B[i];
    }

    MINUS(dp);
    int ans = dfs(0, 0, 0);
    printf("%lld\n", ans);

    return 0;
}
