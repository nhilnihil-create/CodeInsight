#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1e5 + 5;
const int INF = 1001001001;
const ll LINF = 1e15;
const int MOD = 1e9 + 7;

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> H(N);
    rep(i, N) cin >> H[i];

    if (K == N) {
        puts("0");
        return 0;
    }

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, LINF));
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            ll res = LINF;

            int a = H[j - 1];
            rep(k, j) {
                int b = (k > 0)? H[k - 1] : 0;
                int x = max(0, a - b);
                res = min(res, dp[i - 1][k] + x);
            }

            dp[i][j] = res;
        }
    }

    ll ans = LINF;
    for (int i = 1; i <= N; ++i) {
        ans = min(ans, dp[N - K][i]);
    }

    cout << ans << endl;
}