#include <iostream>
#include <string>
using namespace std;
constexpr int mod = 1'000'000'007;
static int dp[100'010][2];
// Let X = A + B
// dp[i][0] --> first i digits, L = X
// dp[i][1] --> first i digits, L > X
// don't care --> first i digits, L < X
int main() {
    string l;
    cin >> l;
    const int n = (int)l.length();

    // L_0 == '1'
    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i = 0; i < n; i++) {
        auto cnt_eq = 0LL;
        auto cnt_lt = 0LL;

        if (l[i] == '0') { // AND X[i] == '0'
            cnt_eq += dp[i][0];
            cnt_lt += dp[i][1];
        }
        if (l[i] == '0') { // AND X[i] == '1'
            // case 1: A[i]=0, B[i]=1
            cnt_eq += 0;
            cnt_lt += dp[i][1];
            // case 2: A[i]=1, B[i]=0
            cnt_eq += 0;
            cnt_lt += dp[i][1];
        }
        if (l[i] == '1') { // AND X[i] == '0'
            cnt_eq += 0;
            cnt_lt += dp[i][0] + dp[i][1];
        }
        if (l[i] == '1') { // AND X[i] == '1'
            // A[i]=0, B[i]=1
            cnt_eq += dp[i][0];
            cnt_lt += dp[i][1];
            // A[i]=1, B[i]=0
            cnt_eq += dp[i][0];
            cnt_lt += dp[i][1];
        }

        dp[i + 1][0] = cnt_eq % mod;
        dp[i + 1][1] = cnt_lt % mod;
    }

    cout << ((dp[n][0] + dp[n][1]) % mod);
    return 0;
}
