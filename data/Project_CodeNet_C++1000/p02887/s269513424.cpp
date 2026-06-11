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
    int n; cin >> n;
    string s; cin >> s;
    char cur = s[0];
    int ans = 1;
    for(int i = 1; i < n; ++i){
        if(s[i] == cur){
            continue;
        }else{
            ++ans;
            cur = s[i];
        }
    }
    cout << ans << '\n';
    return 0;
}