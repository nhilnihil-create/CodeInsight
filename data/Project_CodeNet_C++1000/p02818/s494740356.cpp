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
    ll a, b, k; cin >> a >> b >> k;
    ll cpy = a;
    a -= k;
    if(a < 0){
        k -= cpy;
        a = 0;
        b -= k;
        if(b < 0) b = 0;
    }
    return cout << a << ' ' << b << '\n', 0;
}