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

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    if(N % 2 != 0 || N == 4) {
        // 真ん中から割って割り当てる
        int cur1 = N / 2;
        int cur2 = cur1 + 1;
        REP(i, M) {
            printf("%lld %lld\n", cur1, cur2);
            cur1--;
            cur2++;
        }
    }
    else {
        // 空ける間隔で偶奇に分けて詰めていく
        // 偶数(奇数)間隔から
        int lb = 1;
        int rb = lb + M;
        while(lb < rb) {
            printf("%lld %lld\n", lb, rb);
            lb++;
            rb--;
        }
        // 奇数(偶数)間隔
        lb = M + 2;
        rb = lb + M - 1;
        while(lb < rb) {
            printf("%lld %lld\n", lb, rb);
            lb++;
            rb--;
        }
    }

    return 0;
}
