#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
#define check cout<<"?\n";
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    string s, t; cin >> s >> t;
    int ans = 0;
    for(int i = 0; i < 3; ++i){
        if(s[i] == t[i]) ++ans;
    }
    cout << ans << '\n';
    return 0;
}
