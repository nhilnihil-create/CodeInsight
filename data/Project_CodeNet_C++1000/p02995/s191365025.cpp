#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll gcd(ll x, ll y){

    if(x%y == 0)return y;

    return gcd(y, x%y);
}
int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll sum = b - a + 1;
    ll x, y, z;//c,d,cdの倍数

    if(a%c == 0) x = b/c - a/c + 1;
    else x = b/c - a/c;

    if(a%d == 0) y = b/d - a/d + 1;
    else y = b/d - a/d;

    ll e = c*d/gcd(c, d);
    if(a%e== 0) z = b/e - a/e + 1;
    else z = b/e - a/e;

    sum = sum - x - y + z;

    cout << sum << endl; 
}