#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 200000000
#define mod 1000000007
#define INF2 1000000000000000000


int dp[1010][(1 << 12)];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    rep(i, 1010) rep(j, (1 << 12)) dp[i][j] = INF;
    dp[0][0] = 0;
    int a[1010], b[1010];
    int c[1010][12];
    rep(i, M) {
        cin >> a[i] >> b[i];
        rep(j, b[i]) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    rep(i, M) {
        int key = 0;
        rep(j, b[i]) {
            key |= (1 << c[i][j]);
        }
        rep(bit, (1 << N)) dp[i + 1][bit] = dp[i][bit];
        rep(bit, (1 << N)) {
            int set = bit | key;
            dp[i + 1][set] = min(dp[i + 1][set], dp[i][bit] + a[i]);
        }
    }
    if(dp[M][(1 << N) - 1] == INF) dp[M][(1 << N) - 1]  = -1;
    cout << dp[M][(1 << N) - 1] << endl;

    return 0;
}
