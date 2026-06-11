#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, l, ans, absl;
    
    cin >> n >> l;
    
    ans = 0;
    absl = 10000;
    for ( int i = 1; i <= n; i++ ) {
        ans += l+i-1;
        
        if ( abs(l+i-1) < abs(absl) ) {
            absl = l+i-1;
        }
    }
    
    
    cout << ans - absl << endl;
    return (0);
}