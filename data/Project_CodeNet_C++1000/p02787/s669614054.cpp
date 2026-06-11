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
const int MAX_H = 50000;
int main()
{
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(MAX_H, INF));

    dp[0][0] = 0;
    rep(i, N) {
        rep(j, MAX_H) {
            if (j < A[i]) {
                chmin(dp[i + 1][j], dp[i][j]);
            }
            else {
                chmin(dp[i + 1][j], min(dp[i][j], dp[i + 1][j - A[i]] + B[i]));
            }
        }
        for (int j = MAX_H - 2; j >= 0; j--) {
            chmin(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
/*
    rep(i, N + 1) {
        rep(j, 2 * H + 1) {
            cout << (dp[i][j] == INF ? -1 : dp[i][j]) << " ";
        }
        cout << endl;
    }
*/

    ll ans = INF;
    repd(i, H, MAX_H) chmin(ans, dp[N][i]);
    cout << ans << endl;
    return 0;
}