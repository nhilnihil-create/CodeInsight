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

        int n = s.size();
        string l = s.substr(0, n / 2);
        string r = s.substr((n + 1) / 2, n / 2);

        string lc = l, rc = r, sc = s;
        reverse(lc.begin(), lc.end());
        reverse(rc.begin(), rc.end());
        reverse(sc.begin(), sc.end());

        if(l == lc && r == rc && s == sc)
            cout << "Yes\n";
        else
            cout << "No\n";
        
    }
    
    return 0;
}

