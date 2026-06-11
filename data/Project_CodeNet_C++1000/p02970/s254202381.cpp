#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, d, ar;
    cin >> n >> d;
    
    ar = d + d + 1;
    if ( n % ar == 0 ) {
        cout << n / ar << endl;
    } else {
        cout << n / ar + 1 << endl;
    }
    return (0);
}