// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        string s;
        cin >> s;

        int x = 0, y = 1, ans = 0;
        map<int, int> mp;
        mp[x]++;
        int n = s.size(), k = 2019;
        for(int i = n - 1; i >= 0; i--) {
            x = ((s[i] - '0') * y + x) % k;
            y = y * 10 % k;
            ans += mp[x];
            mp[x]++;
        }

        cout << ans << '\n';

        
    }
    
    return 0;
}

