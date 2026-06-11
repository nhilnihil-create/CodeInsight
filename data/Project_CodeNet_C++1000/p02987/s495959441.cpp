#include <bits/stdc++.h>
using namespace std;

signed main() {
    int alpha[26] = {};
    
    string s;
    cin >> s;
    for ( int i = 0; i < 4; i++ ) {
        alpha[ s[i] - 'A' ] ++;
    }
    sort(alpha, alpha + 26, greater<int>());
    
    if ( alpha[0] == 2 && alpha[1] == 2 ) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return (0);
}