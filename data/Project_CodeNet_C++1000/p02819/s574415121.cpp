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
    int x; cin >> x;
    for(int i = x;; ++i){
        bool ok = 1;
        for(int j = 2; j*j <= i; ++j){
            if(i % j == 0){
                ok &= 0;
                break;
            }
        }   
        if(ok){
            return cout << i << '\n', 0;
        }
    }
    return 0;
}