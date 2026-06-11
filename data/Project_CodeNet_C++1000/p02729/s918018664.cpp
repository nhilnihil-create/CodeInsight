// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n, m;
        cin >> n >> m;

        int ans = n * (n - 1) / 2 + m * (m - 1) / 2;
        cout << ans << '\n';
        
    }
    
    return 0;
}

