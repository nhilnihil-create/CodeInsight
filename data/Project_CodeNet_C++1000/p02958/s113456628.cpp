#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, p[50], sp[50], ans;
    string s;
    
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> p[i];
        sp[i] = p[i];
    }
    s = "NO\n";
    sort(sp, sp + n);
    
    for ( int i = 0; i < n; i++ ) {
        for ( int j = i; j < n; j++ ) {
            swap(p[i], p[j]);
            ans = 0;
            
            for ( int k = 0; k < n; k++ ) {
                if ( sp[k] == p[k] ) {
                    ans++;
                }
            }
            
            if ( ans == n ) {
                s = "YES\n";
            }  
            
            swap(p[i], p[j]);
        }
    }
    
    cout << s;
    return (0);
}