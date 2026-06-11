/**
 *    author:  FromDihPout
 *    created: 2020-08-21
**/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long cnt1 = 0, cnt2 = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) cnt1++;
        }
        for (int j = 0; j < n; j++) {
            if (a[i] > a[j]) cnt2++;
        }
        ans += cnt1 * k + (((k - 1) * k / 2) % MOD) * cnt2 % MOD;
        ans %= MOD;
    }
    cout << ans << '\n';
    return 0;
}