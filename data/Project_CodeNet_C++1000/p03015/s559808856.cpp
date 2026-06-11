#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <class T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string L;
    cin >> L;
    int len = L.length();

    vector<vector<ll>> dp(len + 2, vector<ll>(2));
    dp[0][1] = 1;
    for (int i = 0; i <= len; ++i) {
        bool n = L[i] - '0';
        dp[i + 1][1] = (dp[i][1] * (n + 1)) % MOD;
        dp[i + 1][0] = (dp[i][0] * 3 + dp[i][1] * n) % MOD;
    }

    cout << (dp[len][0] + dp[len][1]) % MOD << endl;
    return 0;
}
