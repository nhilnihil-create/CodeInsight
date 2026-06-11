#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    bool ok = 0;
    string s; cin >> s;
    for(int i = 0; i < s.size() - 1; ++i){
        if(s[i] == s[i + 1]){
            ok = 1;
        }
    }
    puts(ok ? "Bad" : "Good");
    return 0;
}