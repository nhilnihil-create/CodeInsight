#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    ull a, b, c, d; cin >> a >> b >> c >> d;
    --a;
    ull cs = b/c - a/c;
    ull ds = b/d - a/d;
    ull lcm = c*d/__gcd(c,d);
    ull cds = b/lcm - a/lcm;
    cout << b - a - cs - ds + cds  << '\n';
    return 0;  
}