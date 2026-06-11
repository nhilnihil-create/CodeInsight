#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

vector<vector<int>> calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int>> res(n + 1, vector<int>(10, n));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 10; ++j)
            res[i][j] = res[i + 1][j];
        res[i][S[i] - '0'] = i;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string s;
    cin >> N >> s;

    int ans = 0;
    vector<vector<int>> next = calcNext(s);
    vector<vector<int>> dp(N + 1, vector<int>(4));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k <= 2; k++) {
            for (int j = 0; j < 10; j++) {
                if (next[i][j] >= N)
                    continue;
                dp[next[i][j] + 1][k + 1] += dp[i][k];
            }
        }
    }

    rep(i, N + 1) { ans += dp[i][3]; }

    cout << ans << endl;
}