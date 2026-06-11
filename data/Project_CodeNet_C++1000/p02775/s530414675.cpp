#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string N;
    cin >> N;

    int n = N.size();
    vvi dp(n + 1, vi(2, 0));

    rrep(i, 0, n) {
        int ni = int(N[i] - '0');

        bool carry;
        if (i != 0 && dp[i + 1][1] + ni == 5 && int(N[i - 1] - '0') >= 5) {
            carry = true;
        } else if (dp[i + 1][1] + ni <= 5) {
            carry = false;
        } else {
            carry = true;
        }

        if (carry) {
            dp[i][0] = dp[i + 1][0] + 10 - (dp[i + 1][1] + ni);
            dp[i][1] = 1;
        } else {
            dp[i][0] = dp[i + 1][0] + dp[i + 1][1] + ni;
        }
    }

    cout << dp[0][0] + dp[0][1] << endl;
    return 0;
}