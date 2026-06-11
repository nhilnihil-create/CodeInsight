#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, bef = 10;
    string ans = "Good";
    
    cin >> n;
    for ( int i = 0; i < 4; i++ ) {
        if ( n % 10 == bef ) {
            ans = "Bad";
        }
        bef = n % 10;
        n = n / 10;
    }
    cout << ans << endl;
    return (0);
}