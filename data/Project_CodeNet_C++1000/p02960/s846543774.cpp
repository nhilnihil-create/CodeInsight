#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

#define MOD 1000000007
#define M 13

int main() {
    string S; cin >> S;
    int N = S.size();
    vector<vector<ll>> dp(N+1, (vector<ll>(M)));
    dp[0][0] = 1;
    rep(i, N) {
        rep(j, M) {
            if (S[i] != '?') {
                int tmp = (j*10 + (int)(S[i]-'0')) % M;
                dp[i+1][tmp] += dp[i][j];
                dp[i+1][tmp] %= MOD;
                continue;
            }
            rep(k, 10) {
                int tmp = (j*10 + k) % M;
                dp[i+1][tmp] += dp[i][j];
                dp[i+1][tmp] %= MOD;
            }
        }
    }
    cout << dp[N][5] << endl;
}
