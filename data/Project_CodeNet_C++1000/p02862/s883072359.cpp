#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;

const ll mod = 1000000007;

ll rui(ll p, ll k) {
    if(k == 1) {
        return p;
    }
    
    ll pro;
    if(k % 2 == 1) {
        ll r = rui(p,(k-1)/2);
        pro = r * r % mod;
        pro = pro * p % mod;
    }
    else {
        ll r = rui(p,k/2);
        pro = r * r % mod;
    }
    
    return pro;
}

int main() {
    ll x, y;
    cin >> x >> y;
    
    if((x+y)%3) {
        cout << 0 << endl;
        return 0;
    }
    
    ll n = (x+y) / 3;
    x -= n;
    y -= n;
    
    if(x < 0 || y < 0) {
        cout << 0 << endl;
        return 0;
    }
    
    ll mx, mn;
    mx = max(x, y);
    mn = min(x, y);
    
    ll c, p;
    c = p = 1;
    rep(i,mn) {
        c *= mx + mn - i;
        c %= mod;
        
        p *= mn - i;
        p %= mod;
    }
    //cout << c << endl;
    //cout << p << endl;
    
    p = rui(p,mod-2);
    
    cout << c * p % mod << endl;
    
    
    
    return 0;
}
