// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n; 
        cin >> n;
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += (i + 1) * (n - i);
        
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            if (u > v) 
                swap(u, v);
            ans -= u * (n + 1 - v);
        }

        cout << ans << '\n';
        
    }
    
    return 0;
}

