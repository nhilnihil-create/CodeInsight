// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int x, y, n, m, k;
        cin >> x >> y >> n >> m >> k;
        vector<int> a(n), b(m), c(k);
        for(auto &&  x : a)
            cin >> x;
        for(auto &&  x : b)
            cin >> x;
        for(auto &&  x : c)
            cin >> x;

        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        sort(c.begin(), c.end(), greater<int>());

        vector<int> ans;
        for(int i = 0; i < x; i++)
            ans.push_back(a[i]);
        for(int i = 0; i < y; i++)
            ans.push_back(b[i]);
        for(int i = 0; i < min(x + y, k); i++)
            ans.push_back(c[i]);
        sort(ans.begin(), ans.end(), greater<int>());

        int tot = accumulate(ans.begin(), ans.begin() + (x + y), 0LL);
        cout << tot << '\n';
        
    }
    
    return 0;
}

