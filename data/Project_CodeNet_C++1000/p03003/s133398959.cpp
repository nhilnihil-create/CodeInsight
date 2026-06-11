#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
const long long MOD = 1e9 + 7;
typedef pair<int, int> P;

ll dp[2002][2002];
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> S(N), T(M);
    rep(i, N) cin >> S[i];
    rep(i, M) cin >> T[i];

    dp[0][0] = 1;
    rep(i, N + 1) {
        rep(j, M + 1) {
            if (i >= 1 && j >= 1 && (S[i - 1] == T[j - 1])) {
                dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= MOD;
            }
            if (i >= 1) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
            if (j >= 1) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
            if (i >= 1 && j >= 1) {
                dp[i][j] -= dp[i - 1][j - 1];
                dp[i][j] %= MOD;
            }
            if (dp[i][j] < 0) dp[i][j] += MOD;
        }
    }

    cout << dp[N][M] << endl;
    return 0;
}