#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    ll a, b; cin >> a >> b;
    for(ll x = 0; x < max(b,a); ++x){
        if(abs(b - x) == abs(a - x)) return cout << x << '\n', 0;
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}