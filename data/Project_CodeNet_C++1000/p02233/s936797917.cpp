#include <iostream>
const int MAX_N = 50;
using namespace std;

int dp[MAX_N];

int main(void) {
    int n;
    cin >> n;

    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << endl;
    return 0;
}