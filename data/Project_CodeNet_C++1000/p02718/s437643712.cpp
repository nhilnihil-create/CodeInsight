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
        int a[n], tot = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            tot += a[i];
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] * 4 * m >= tot)
                cnt++;
        }

        if(cnt >= m)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    
    return 0;
}

