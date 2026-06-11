#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

int dp[3010][6010];
typedef pair<int, int> P;
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, T;
    cin >> N >> T;
    P plate[3010];
    rep(i, N) cin >> plate[i].first >> plate[i].second;
    sort(plate, plate + N);
    rep(i, N) {
        REP(j, 0, 6000) {
            dp[i + 1][j] = dp[i][j];
            if (j - plate[i].first >= 0 && j - plate[i].first < T)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - plate[i].first] + plate[i].second);
        }
    }
    int ans = 0;
    rep(i, 6001) ans = max(ans, dp[N][i]);
    cout << ans << endl;

    return 0;
}
