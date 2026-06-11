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
    bool ok = 1;
    string s; cin >> s;
    for(int i = 0; i < (int)s.size() && ok; ++i){
        if(i & 1){
            if(s[i] == 'R') ok &= 0;
        }else{
            if(s[i] == 'L') ok &= 0;
        }
    }
    puts(ok ? "Yes":"No");
    return 0;
    
}