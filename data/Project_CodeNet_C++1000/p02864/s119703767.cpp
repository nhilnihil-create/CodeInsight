#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
using ll = long long;

template <class T>
void chmin(T &a, T b) {
    if (b < a) a = b;
}

int main() {
    int n, k;
    cin >> n >> k;

    int m = n - k;
    if (m == 0) {
        cout << 0 << endl;
        exit(0);
    }

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    //dp[i]:l個の塊で最後の高さがh[i]のときの最小
    vector<ll> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = h[i];
    }
    for (int l = 1; l < m; l++) {
        for (int i = n - 1; i >= l; i--) {
            ll t = 1LL << 60;
            for (int j = l - 1; j < i; j++) {
                chmin(t, dp[j] + max(h[i] - h[j], 0));
            }
            dp[i] = t;
        }
    }

    cout << *min_element(dp.begin() + m - 1, dp.end()) << endl;

    return 0;
}