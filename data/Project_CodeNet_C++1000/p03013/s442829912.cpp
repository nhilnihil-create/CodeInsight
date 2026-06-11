#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int N, M;
    cin >> N >> M;
    vector <bool> T(N);
    while (M--) {
        int a;
        cin >> a;
        T[a - 1] = true;
    }
    vector <ll> dp(N + 1);
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        if (!T[i]) {
            dp[i + 1] = (dp[i] + (i >= 1 ? dp[i - 1] : 0)) % 1000000007;
        }
    }
    cout << dp[N] << endl;
}