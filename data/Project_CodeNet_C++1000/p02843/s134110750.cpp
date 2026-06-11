#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;

int main() {
    int X;
    cin >> X;
    vector<bool> dp(X + 1);
    dp[0] = 1;
    rep(i, X + 1) {
        if (dp[i]) FOR(j, 100, 106) {
            if (i + j <= X) dp[i + j] = 1;
        }
    }
    cout << dp[X] << endl;
    return 0;
}