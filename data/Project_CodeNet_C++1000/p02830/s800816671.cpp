#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

signed main(){
    io();
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    string ans = "";
    for(int i = 0; i < n; ++i){
        ans += s1[i];
        ans += s2[i];
    }
    cout << ans << '\n';
    return 0;
}