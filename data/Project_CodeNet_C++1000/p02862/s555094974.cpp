#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
using ll = long long;

const ll mod = 1000000007;

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
 
ll modinv(ll a, ll mod) {
    return modpow(a, mod - 2, mod);
}
 
ll nCr(ll n, ll r) {
    ll ans = 1;
    for (ll i = n; i > n - r; --i) {
        ans = ans * i % mod;
    }
    for (ll i = 1 ; i < r + 1; ++i) {
        ans = ans * modinv(i, mod) % mod;
    }
    return ans;
}

int main(){
    ll x, y;
    cin >> x >> y;
    if((x + y) % 3 != 0){
        cout << "0" << endl;
    } else {
        ll n = (2*y - x) / 3L;
        ll m = (2*x - y) / 3L;
        if(n < 0 || m < 0){
            cout << "0" << endl;
        } else {
            cout << nCr(n + m, m) << endl;
        }
    }
    return 0;
}
