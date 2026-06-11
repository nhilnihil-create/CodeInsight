#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 1e9+7;

int n, m;
int dp[50001];
int c[50001];

int solve(int n) {
    if (dp[n] != INF) return dp[n];
    int res = INF;
    if (n == 0) res = 0;
    for (int i = 0; i < m; ++i) {
        if (n-c[i] >= 0) res = min(res, solve(n-c[i])+1);
    }
    return dp[n] = res;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i <= n; ++i) dp[i] = INF;
    dp[0] = 0;

    for (int i = 0; i < m; ++i) cin >> c[i];

    cout << solve(n) << endl;

}