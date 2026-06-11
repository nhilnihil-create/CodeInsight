#include <bits/stdc++.h>
using namespace std;

signed main() {
    string s, ans;
    cin >> s;

    ans = "Yes\n";
    for ( int i = 0; i < s.size(); i++ ) {
        if ( i % 2 == 0 && s[i] == 'L' ) {
            ans = "No\n";
        } 
        else if ( i % 2 == 1 && s[i] == 'R' ) {
            ans = "No\n";
        }
    }    
    
    cout << ans;
    return (0);
}