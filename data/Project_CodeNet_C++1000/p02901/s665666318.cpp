#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> dp(M + 1, vector<ll>(1 << N, INF));

    vector<int> a(M), b(M);
    vector<vector<int>> c(M);
    rep(i, M) {
        cin >> a[i] >> b[i];
        rep(j, b[i]) {
            int t;
            cin >> t;
            c[i].push_back(t);
        }
    }

    dp[0][0] = 0;
    rep(i, M) {
        rep(j, 1 << N) {
            if (dp[i][j] == INF) continue;
            int bit = j;
            rep(k, b[i]) {
                bit |= (1 << (c[i][k] - 1));
            }
            chmin(dp[i + 1][bit], dp[i][j] + a[i]);
            chmin(dp[i + 1][j], dp[i][j]);
        }
    }

    ll ans = dp[M][(1 << N) - 1];
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}