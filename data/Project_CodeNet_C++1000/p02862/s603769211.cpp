#include "bits/stdc++.h"

using namespace  std;

typedef long long ll;

ll mod = 1e9 + 7;


ll fpow(ll a,ll b,ll p){
    ll res = 1;
    while(b > 0) {
        if (b & 1) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return res % p;
}

//求逆元  1/(n-m)! = inv((n-m)!)
ll pw(ll a,ll p){
    return fpow(a,p-2,p);
}

ll nCk(ll n, ll k,ll p){
    ll f[1000010];
    f[0] = 1;
    for(int i = 1;i<=n;i++){
        f[i] = f[i-1] * i % p;
    }
    return f[n] * fpow(f[n-k],p-2,p) % p * fpow(f[k],p-2,p) % p;
}
ll x,y;
int main(){
    cin >> x >> y;

    if((x + y) % 3 || (x + x - y) < 0 || (y + y - x)< 0){
        cout << 0 << endl;
    }else{
        ll a = (x + x - y)/3;
        ll b = (y + y - x)/3;
        cout << nCk(a + b,b,mod) << endl;
    }
    return 0;
}