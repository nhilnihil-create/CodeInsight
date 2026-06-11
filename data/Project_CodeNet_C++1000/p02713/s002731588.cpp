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
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= n; k++)
                    ans += __gcd(i, __gcd(j, k));
            }
        }

        cout << ans << '\n';
    }
    
    return 0;
}

