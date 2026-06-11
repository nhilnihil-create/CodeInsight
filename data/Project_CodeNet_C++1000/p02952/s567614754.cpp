#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, ans;
    
    cin >> n;
    ans = 0;
    
    for ( int i = 1; i <= n; i++ ) {
        if ( (i >= 1 && i < 10) || (i >= 100 && i < 1000) || ( i >= 10000 && i < 100000) ) {
            ans++;
        }
    }
    
    cout << ans << endl;
    return (0);
}