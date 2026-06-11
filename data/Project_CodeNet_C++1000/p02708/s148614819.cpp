/**
 *    author:  FromDihPout
 *    created: 2020-08-29
**/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n, k;
    cin >> n >> k;
    
    vector<int> pref(n+1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + i;
        pref[i] %= MOD;
    }
    
    long long ans = 0;
    for (int i = k; i <= n + 1; i++) {
        if (i < n + 1) {
            ans += (pref[n] - pref[n-i]) - pref[i-1] + 1;
        }
        else {
            ans++;
        }
        ans = ((ans % MOD) + MOD) % MOD;
    }
    cout << ans << '\n';
    
    return 0;
}
