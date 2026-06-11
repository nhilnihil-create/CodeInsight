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

        set<string> st;
        while(n--) {
            string s;
            cin >> s;
            st.insert(s);
        }

        cout << st.size() << '\n';
        
    }
    
    return 0;
}

