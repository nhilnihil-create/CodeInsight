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
    string s; cin >> s;
    if(s[0] == 'S'){
        if(s[1] == 'A'){
            cout << 1 << '\n';
        }else{
            cout << 7 << '\n';
        }
    }else if(s[0] == 'T'){
        if(s[1] == 'U'){
            cout << 5 << '\n';
        }else{
            cout << 3 << '\n';
        }
    }else if(s[0] == 'W'){
        cout << 4 << '\n';
    }else if(s[0] == 'M'){
        cout << 6 << '\n';
    }else{
        cout << 2 << '\n';
    }
    return 0;
}