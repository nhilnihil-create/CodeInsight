#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main(){
    ll h;
    cin >> h;
    ll n = 0;
    while(h){
        n++;
        h /= 2;
    }
    ll ans = pow(2,n) - 1;
    cout << ans << endl;
}