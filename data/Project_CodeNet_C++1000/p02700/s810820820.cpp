// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        int ha, sa, hb, sb;
        cin >> ha >> sa >> hb >> sb;

        while(ha > 0) {
            hb -= sa;
            if(hb <= 0)
                break;
            ha -= sb;
        }

        if(ha > 0)
            cout << "Yes\n";
        else
            cout << "No\n";
        
    }
    
    return 0;
}

