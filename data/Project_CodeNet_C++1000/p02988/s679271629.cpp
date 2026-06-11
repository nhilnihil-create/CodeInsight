#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, p[20], ans;

    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> p[i];
    }
    
    ans = 0;
    for ( int i = 1; i < n-1; i++ ) {
        if ( (p[i] > p[i-1] && p[i] < p[i+1]) || (p[i] < p[i-1] && p[i] > p[i+1]) ) {
            ans ++;
        }
    }
    
    cout << ans << endl;
    return (0);
}