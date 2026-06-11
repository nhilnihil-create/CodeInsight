// 7/1 解き直し
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

ll dp[100010];

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    rep(i, M) cin >> a[i];
    a.push_back(N+1);

    rep(i, 100010) dp[i] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= mod;
    }

    ll res = 1;
    ll prev = 0;
    for (int i = 0; i <= M; i++) {
        int distance = a[i] - 1 - prev;
        if (distance < 0) {
            cout << 0 << endl;
            return 0;
        }
        res *= dp[distance];
        res %= mod;
        prev = a[i] + 1;
        // printf("distance, dp[distance], res = %d, %d, %d\n", distance, dp[distance], res);
    }

    cout << res << endl;
}