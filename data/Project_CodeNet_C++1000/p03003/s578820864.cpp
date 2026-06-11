#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2005;
const ll MOD = 1e9 + 7;

int n, m;
ll dp[N][N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    
    rep(i, 0, N) {
        dp[0][i] = 1;
        dp[i][0] = 1;
    }

    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = (2 * dp[i - 1][j - 1]) % MOD + (dp[i - 1][j] + dp[i][j - 1] - 2 * dp[i - 1][j - 1]);
                if (dp[i][j] < 0) dp[i][j] += MOD;
                dp[i][j] %= MOD;
            } else {
                dp[i][j] = ((dp[i - 1][j] + dp[i][j - 1]) % MOD - dp[i - 1][j - 1] + MOD) % MOD;
                if (dp[i][j] < 0) dp[i][j] += MOD;
                dp[i][j] %= MOD;
            }
        }
    }
    
    cout << dp[n][m];
}
