#include "bits/stdc++.h"
using namespace std;
#define int long long
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, a, b) for(int i=(b-1);i>=(a);i--)
#define REP(i, n) for(int i=0; i<(n); i++)
#define RREP(i, n) for(int i=(n-1); i>=0; i--)
#define REP1(i, n) for(int i=1; i<=(n); i++)
#define RREP1(i, n) for(int i=(n); i>=1; i--)
#define ALL(a) (a).begin(),(a).end()
#define UNIQUE_SORT(l) sort(ALL(l)); l.erase(unique(ALL(l)), l.end());
#define CONTAIN(a, b) find(ALL(a), (b)) != (a).end()
#define out(...) printf(__VA_ARGS__)

int dxy[] = {0, 1, 0, -1, 0};

void solve();
signed main()
{
#if DEBUG
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

/*================================*/
#if DEBUG
#define SIZE 333
#else
#define SIZE 333
#endif

int N,K;

/*
 ■塗る回数のカウント
 左から見ていって、、
 上がっている間は差分を+
   (一度下がってから上がった場合も含む)
 下がっている間は+0
 ■変化の方向
 隣に高さを合わせると、カウントに影響しなくできる
 */
// i番目のブロックまでみた、残り変化回数、直前の高さ(ブロック番号)→最小の塗る回数
int DP[SIZE][SIZE][SIZE];
int LAST = SIZE-1;
int H[SIZE];
void solve() {
    cin>>N>>K;
    REP(i,N)cin>>H[i];
    
    REP(i,N)REP(k,K+1)REP(j,SIZE) {
        DP[i][k][j] = LONG_LONG_MAX/3;
    }
    if (K) DP[0][K-1][LAST] = 0;
    DP[0][K][0] = H[0];
    FOR(i,1,N)REP(k,K+1)FOR(_j,-1,i) {
        int j = (_j<0) ? LAST : _j;
        if (k<K) DP[i][k][j] = min(DP[i][k][j], DP[i-1][k+1][j]); // 操作→直前の高さはjのまま
        int lastH = (_j<0) ? 0 : H[_j];
        DP[i][k][i] = min(DP[i][k][i], DP[i-1][k][j] + max(0LL, H[i]-lastH)); // 普通に塗る→直前の高さはi
    }
    int ans = LONG_LONG_MAX;
    REP(k,K+1)FOR(_j,-1,N) {
        int j = (_j<0) ? LAST : _j;
        ans = min(ans, DP[N-1][k][j]);
    }
    cout << ans << endl;
}