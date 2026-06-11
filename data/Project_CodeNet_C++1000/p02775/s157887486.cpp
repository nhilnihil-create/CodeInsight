#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pdd = pair<double, double>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string N;
    cin >> N;

    int Nlen = N.length();
    vector<vector<int>> dp(Nlen + 3, vector<int>(2, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i <= Nlen; ++i) {
        int num = (i < Nlen ? N[i] - '0' : 0);
        dp[i + 1][0] = min(dp[i][0] + num, dp[i + 1][0]);
        if (num != 9)
            dp[i + 1][0] = min(dp[i][1] + num + 1, dp[i + 1][0]);
        dp[i + 1][1] = min(dp[i][1] + 9 - num, dp[i + 1][1]);
        if (num != 0)
            dp[i + 1][1] = min(dp[i][0] + 10 - num, dp[i + 1][1]);
    }

    cout << dp[Nlen + 1][0] << endl;

    return 0;
}
