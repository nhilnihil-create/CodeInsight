#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define GET_ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))
#define LL long long
int main(){
    string s,t;
    LL ans = 0;
    cin >> s;
    cin >> t;
    for (int i = 0; i < s.length(); i++) {
        if(s[i] == t[i]) {
           ans++; 
        }
    }
    cout << ans << endl;
    return 0;
}