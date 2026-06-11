// ABC163-D Sum of Large Numbers
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

signed main() {
    long long n, k;
    long long ans, a, b;

    cin >> n >> k;
    
    ans = 0;
    for(long long i=k ;i<=n+1 ;i++ ) {
        a = i * (2 * n - i + 1) / 2; // 選べる最大値
        b = i * (i - 1) / 2; // 選べる最小値

        ans = (a - b + 1 + ans) % MOD;
    }

    cout << ans << endl;

    return (0);
}
