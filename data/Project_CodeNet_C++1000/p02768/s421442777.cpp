#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <set>
#include <cmath>
#include <queue>

typedef long long ll;

using namespace std;


ll mod = pow(10, 9) + 7;

ll re(ll n, ll sq){
    if(sq == 0) return 1;
    if(sq % 2 == 0){
        ll t = re(n, sq / 2);
        return t * t % mod;
    } else {
        ll t = re(n, sq - 1);
        return n * t % mod;
    }
}


int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll bc = 1;
    ll bb = 1;
    for(int i = 0; i < a; i++){
        bc = (bc * (n - i)) % mod;
        bb = (bb * (i + 1)) % mod;
    }
    ll bbg = re(bb, mod - 2);
    ll ad = (bc % mod) * (bbg % mod) % mod;

    bc = 1;
    bb = 1;
    for(int i = 0; i < b; i++){
        bc = (bc * (n - i)) % mod;
        bb = (bb * (i + 1)) % mod;
    }

    bbg = re(bb, mod - 2);
    ll bd = (bc % mod) * (bbg % mod) % mod;

    ll ans = (re(2, n) - 1);
    ans = ((ans - ad) % mod - bd) % mod;

    if(ans < 0){
        cout << mod + ans << endl;
    } else {
        cout << ans << endl;
    }
}