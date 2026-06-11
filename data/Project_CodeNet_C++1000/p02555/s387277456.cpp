#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
    int mod = 1000000007;
    int s;
    cin >> s;
    vector<int> dp(s+1, 0);
    dp[0] = 1;
    for(int i = 3; i <= s; ++i) {
        for(int j = 0; j <= i-3; ++j) {
            dp.at(i) += dp.at(j);
            dp.at(i) %= mod;
        }
    }

    cout << dp.at(s) << endl;
    return 0;
}
