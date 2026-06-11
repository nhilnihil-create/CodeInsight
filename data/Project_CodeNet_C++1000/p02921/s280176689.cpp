#include <bits/stdc++.h>
using namespace std;

signed main() {
    int ans;
    string s, t;
    
    cin >> s >> t;
    ans = 0;
    for ( int i = 0; i < 3; i++ ) {
        if ( s[i] == t[i] ) {
            ans ++;
        }
    }
    
    cout << ans << endl;
    return (0);
}