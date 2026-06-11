#include <bits/stdc++.h>
using namespace std ;
string s,t ;

int solve(int pos) {
    int ans = 0 ;
    for(int i = 0;i < t.length(); ++ i) {
        if(s[pos + i] != t[i]) {
            ++ ans ;
        }
    }
    return ans ;
}

int main()
{
    int64_t D, T, S ;
    ios::sync_with_stdio(false) ;
    while(cin >> s >> t) {
        int lens = s.length(), lent = t.length() ;
        int ans = 0x3f3f3f3f ;
        for(int i = 0;i + lent - 1 < lens; ++ i) {
            ans = min(ans, solve(i)) ;
        }
        cout << ans << endl ;
    }
}
