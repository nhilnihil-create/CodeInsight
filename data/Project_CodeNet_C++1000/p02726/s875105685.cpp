// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int n, x, y;
        cin >> n >> x >> y;

        map<int, int> mp;
        for(int i = 1; i < n; i++)
            mp[i] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                int dist = min({abs(i - j), abs(i - x) + 1 + abs(y - j), abs(i - j) + 1 + abs(x - j)});
                mp[dist]++;
            }
        }

        for(auto x : mp)
            cout << x.second << '\n';
        
    }
    
    return 0;
}

