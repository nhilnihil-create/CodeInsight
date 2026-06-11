#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, a[50], b[50], c[50], ans;
    
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
        a[i]--;
    }
    for ( int i = 0; i < n; i++ ) {
        cin >> b[i];
    }
    for ( int i = 0; i < n-1; i++ ) {
        cin >> c[i];
    }
    
    ans = 0;
    for ( int i = 0; i < n; i++ ) {
        ans += b[ a[i] ];
        
        if ( i < n-1 && a[i] == a[i+1]-1 ) {
            ans += c[ a[i]];
        }
    }
    
    cout << ans << endl;
    return (0);
}