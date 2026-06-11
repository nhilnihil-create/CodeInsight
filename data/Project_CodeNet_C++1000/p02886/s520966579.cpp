#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, d, sum, ans;
    cin >> n;
    
    sum = ans = 0;
    for ( int i = 0; i < n; i++ ) {
        cin >> d;
        
        ans += d * sum;
        sum += d;
    }
    
    cout << ans << endl;
    return (0);
}