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

        if(s[2] == s[3] && s[4] == s[5])
            cout << "Yes\n";
        else
            cout << "No\n";
        
    }
    
    return 0;
}

