#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
int dp[2100];

int main() {
    int S; cin >> S;
    dp[0] = 1;
    for (int i = 1; i <= S; i++) {
        for (int j = 0; j <= i - 3; j++) {
            dp[i] += dp[j];
            dp[i] %= MOD;
        }
    }
    cout << dp[S] << endl;
    return 0;
}