#include <bits/stdc++.h>
using namespace std;

signed main() {
    long long n, l[100], x, far, ans;
    cin >> n >> x;
    for ( int i = 0; i < n; i++ ) {
        cin >> l[i];
    }
    
    far = 0;
    ans = 0;
    for ( int i = 0; i < n && far <= x; i++ ) {
        far += l[i];
        ans ++;
    }
    
    if ( far <= x ) {
        ans ++;
    }
    cout << ans << endl;
    return (0);
}