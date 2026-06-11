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
const int MAX_N = 200010;

string S, T;
// i 以降にあるアルファベット j のうち一番手前のものの位置
// ない場合 -1
int pos[MAX_N][30];

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> S >> T;

    // pos の作成
    string S2 = S + S;
    MINUS(pos);
    for(int i = S2.length() - 1; i >= 0; i--) {
        REP(j, 30) {
            pos[i][j] = pos[i+1][j];
        }
        int cur = S2[i] - 'a';
        pos[i][cur] = i;
    }

    // t を順番に見ていく
    int ans = 0;
    int cur = 0;
    REP(i, T.length()) {
        // T[i] は S[cur] から何番目にあるか
        int next_cur = pos[cur][T[i] - 'a'];
        if(next_cur < 0) {
            ans = -1;
            break;
        }
        ans += (next_cur - cur) + 1;
        //DBG("T[i]: %c cur: %lld next_cur: %lld -> ", T[i], cur, next_cur);
        if(next_cur + 1 < S.length()) {
            cur = next_cur + 1;
        }
        else {
            cur = next_cur + 1 - S.length();
        }
        //DBG("%lld\n", cur);
    }
    printf("%lld\n", ans);

    return 0;
}
