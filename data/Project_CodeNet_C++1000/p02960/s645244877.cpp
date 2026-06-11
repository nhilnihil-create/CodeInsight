#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

const ll mod = 13;

int main()
{
    string S;
    cin >> S;
    int N = S.size();
    vector<vector<ll>> dp(N + 5, vector<ll>(mod, 0));

    if (S[0] == '?') {
        for (int j = 0; j < 10; j++)
            dp[1][j] = 1;
    } else {
        int j = (int)(S[0] - '0');
        dp[1][j] = 1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < mod; j++) {
            if (S[i] == '?') {
                for (int k = 0; k < 10; k++) {
                    int nj = (j * 10 + k) % mod;
                    dp[i + 1][nj] += dp[i][j];
                    dp[i + 1][nj] %= MOD;
                }
            } else {
                int k = (int)(S[i] - '0');
                int nj = (j * 10 + k) % mod;
                dp[i + 1][nj] += dp[i][j];
                dp[i + 1][nj] %= MOD;
            }
        }
    }

    cout << dp[N][5] << endl;
    return 0;
}
