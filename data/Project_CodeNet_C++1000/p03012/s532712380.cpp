#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, w[101], ans;
    cin >> n;
    
    w[0] = 0;
    ans = 0;
    for ( int i = 1; i <= n; i++ ) {
        cin >> w[i];
        w[i] += w[i-1];
        ans += w[i];
    }
    
    for ( int i = 0; i < n; i++ ) {
        ans = min(ans, abs((w[n] - w[i+1]) - w[i+1]));
    }
    
    cout << ans << endl;
    return (0);
}