#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll x, ll y){
    if(x < y) swap(x, y);
    while(y){
        ll r = x % y;
        x = y;
        y = r;
    }
    return x;
}

ll lcm(ll x, ll y){
    ll g = gcd(x, y);
    return (x / g) * (y / g) * g;
}

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    auto divs = [&](ll x){
        return b / x - (a + x-1) / x + 1;
    };
    cout << b - a + 1 - divs(c) - divs(d) + divs(lcm(c, d)) << endl;
    return 0;
}