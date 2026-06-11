#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e+9 + 7;

ll power(ll a, ll x){
    if(x == 0) return 1;
    if(x & 1) return a * power(a, x-1) % mod;
    return power(a * a % mod, x / 2);
}

ll fact(ll n){
    //if(n == 0) return 1;
    //return n * fact(n-1) % mod;
    ll res = 1;
    for(int i = 1; i <= n; i++){
        res = res * i % mod;
    }
    return res;
}

ll combi(ll n, ll r){
    ll tmp = fact(n) * power(fact(r), mod-2) % mod;
    return tmp * power(fact(n-r), mod-2) % mod;
}

int main(){
    int x, y;
    cin >> x >> y;
    int a = (2*y - x) / 3;
    int b = (2*x - y) / 3;
    if((2*y - x) % 3 != 0 || (2*x - y) % 3 != 0
        || a < 0 || b < 0){
        cout << 0 << endl;
        return 0;
    }
    cout << combi(a + b, a) << endl;
    return 0;
}