#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


ll h,w;
vector<string> v(50);

ll modpow(ll a, ll n) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return ret;
}

ll modinv(ll a) { return modpow(a, MOD - 2); }

ll comb(ll n, ll r) {
    ll ret = 1;
    for (ll i = 0; i < r; i++) ret = ret * (n - i) % MOD;
    for (ll i = 1; i <= r; i++) ret = ret * modinv(i) % MOD;
    return ret;
}

int main(){

    ll x,y; cin >> x >> y;
    ll cx = 0,cy = 0;
    ll tx = x, ty = y;

    while(ty > 0 && tx > 0){
        if(ty > tx){
            ty -= 2;
            tx -= 1;
            cy += 1;
        }else{
            ty -= 1;
            tx -= 2;
            cx += 1;
        }
    }

    if(tx == 0 && ty == 0){
        ll sum = cx + cy;
        cout << comb(sum, cx);
    }else{
        cout << 0;
    }

    /*
    if(x == y) {
        if (x % 3 == 0 && y % 3 == 0) {
            cout << comb(x / 3 * 2, x / 3);
        }else{
            cout << 0;
        }
    }
*/

}