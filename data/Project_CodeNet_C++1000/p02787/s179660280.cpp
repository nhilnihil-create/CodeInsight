#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
const int H_MAX = 50000;
typedef pair<int, int> P;
int main()
{
    int H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);

    rep(i, N) cin >> A[i] >> B[i];

    vector<vector<ll>> dp(N + 1, vector<ll>(H_MAX, INF));

    rep(i, N + 1) dp[i][0] = 0;

    rep(i, N) {
        rep(j, H_MAX) {
            if (j < A[i]) {
                dp[i + 1][j] = dp[i][j];
            }
            else {
                dp[i + 1][j] = min(dp[i][j], dp[i + 1][j - A[i]] + B[i]);
            }
        }/*
        ll m = INF;
        for (int j = H_MAX - 1; j >= 0; j--) {
            chmin(m, dp[i + 1][j]);
            chmin(dp[i + 1][j], m);
        }*/
    }

    ll ans = INF;
    repd(i, H, H_MAX) {
        chmin(ans, dp[N][i]);
    }

    cout << ans << endl;
    return 0;
}