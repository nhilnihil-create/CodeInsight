#include <iostream>
typedef long long ll;
using namespace std;
static const int MOD = 1000000007;

// DPテーブル
ll dp[2005];


int main() {
    int S;
    cin >> S;
    // 初期条件
    dp[0] = 1;
    for (int i = 3; i <= S; i++) {
        dp[i] = (dp[i - 1] + dp[i - 3]) % MOD;
    }
    if (S >= 1 && S <= 2) cout << 0 << endl;
    else cout << dp[S] << endl;

    return 0;
}