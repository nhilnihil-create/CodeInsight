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
    int aux = 1;
    bool ok = 0;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        if(x == aux){
            ++aux;
            ok = 1;
        }
    }
    cout << (ok ? n - aux + 1 : -1) << '\n';
    return 0;
}