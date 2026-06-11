#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> dp(n);
    dp[0] = 1000;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], (dp[j] / a[j]) * a[i] + (dp[j] % a[j]));
        }
    }

    cout << dp[n - 1] << endl;
    return 0;
}