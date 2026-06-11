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
        string s;
        cin >> n >> s;

        map<char, int> mp;
        for(auto c : s)
            mp[c]++;

        int ans = mp['R'] * mp['G'] * mp['B'];
        s = '#' + s;
        for(int i = 2; i <= n - 1; i++) {
            for(int j = 1; j <= n; j++) {
                int x = i - j;
                int y = i;
                int z = i + j;
                // cout << x << ' ' << y << ' ' << z << '\n';
                if(1 <= x && z <= n && s[x] != s[y] && s[y] != s[z] && s[z] != s[x]) {
                    // cout << x << ' ' << y << ' ' << z << '\n';
                    ans--;
                }
            }
        }

        cout << ans << '\n';
        
    }
    
    return 0;
}

