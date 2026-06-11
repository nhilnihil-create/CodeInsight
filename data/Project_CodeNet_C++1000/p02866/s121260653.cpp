#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 998244353;

signed main() {
    int n;
    cin >> n;
    vector<int> ns(n);
    int N = 1e5 + 10;
    vector<int> arr(N);
    int fst;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (i == 0)
            fst = a;
        ++arr[a];
    }
    vector<int> dp(n);
    int cnt = 1;
    dp[0] = fst == 0;
    if (arr[0] != 1) {
        cout << 0 << endl;
        exit(0);
    }
    for (int i = 1; cnt < n; ++i) {
        for (int j = 0; j < arr[i]; ++j) {
            dp[cnt] = dp[cnt - 1] * arr[i - 1] % mod;
            ++cnt;
        }
    }
    cout << dp[cnt - 1] << endl;
}
