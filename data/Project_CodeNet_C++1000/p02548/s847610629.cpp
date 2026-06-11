#include "bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

#define int long long

#ifndef bhupixb
    #define var(...)
    #define stl(...)
#endif

#define single_test

const int maxn = 1e6 + 4;
int32_t d[maxn];

void solve() {
    for (int i = 1; i < maxn; ++i) {
        for (int j = i; j < maxn; j += i) {
            d[j]++;
        }
    }
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += d[i];
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    #ifndef single_test
        cin >> t;
    #endif
    for (int i = 1; i <= t; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}