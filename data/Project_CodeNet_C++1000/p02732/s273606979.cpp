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
        int a[n + 5];
        map<int, int> mp;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }

        int tot[n + 5];
        for(int i = 1; i <= n; i++) {
            int x = mp[i];
            tot[i] = x * (x - 1) / 2;
        }

        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans += tot[i];

        for(int i = 1; i <= n; i++) {
            int x = a[i], cnt = mp[x];
            cout << ans - (cnt - 1) << '\n';
        }
        
    }
    
    return 0;
}

