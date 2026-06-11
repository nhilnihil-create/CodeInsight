#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

const int MX_N = 305;

int N, K, H[MX_N], ord[MX_N], X[MX_N];
ll dp[2][MX_N][MX_N];

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    H[0] = 0; ord[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> H[i];
        ord[i] = i;
    }
    sort(ord,ord+N+1,[](int a, int b) { if (H[a] == H[b]) return a < b; return H[a] < H[b]; });
    for (int i = 0; i <= N; ++i) X[ord[i]] = i;
    sort(H,H+N+1);

    // dp[i][x][p] = min (dp[i+1][x][i], for all j dp[i+1][x-1][j] + max(H[j]-H[p], 0))
    int c = 0;
    for (int i = N; i >= 1; --i) {
        ll bel[N+1], abv[N+1];
        for (int x = 0; x <= K; ++x) {
            for (int p = 0; p <= N; ++p) {
                dp[c][x][p] = dp[!c][x][X[i]] + max(H[X[i]] - H[p], 0);
                if (x > 0) {
                    dp[c][x][p] = min({ dp[c][x][p], bel[p], abv[p]-H[p] });
                }
                //cout << X[i] << " " << H[X[i]] << " :: " << i << " " << x << " " << p << " :: " << dp[c][x][p] << endl;
            }

            bel[0] = dp[!c][x][0];
            abv[N] = dp[!c][x][N] + H[N];
            for (int p = 1; p <= N; ++p) {
                bel[p] = min(bel[p-1], dp[!c][x][p]);
                abv[N-p] = min(abv[N-p+1], dp[!c][x][N-p] + H[N-p]);
            }
        }
        c = !c;
    }
    cout << dp[!c][K][0] << '\n';
}

