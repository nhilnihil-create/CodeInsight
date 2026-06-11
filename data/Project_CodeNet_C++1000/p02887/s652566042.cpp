#include <bits/stdc++.h>
using namespace std;  

int main(){
    int n, ans;
    string s;
    
    cin >> n;
    cin >> s;
    ans = n;
    
    for ( int i = 1; i < n; i++ ) {
        if ( s[i] == s[i-1] ) {
            ans --;
        }
    }
    
    cout << ans << endl;
    return (0);
}