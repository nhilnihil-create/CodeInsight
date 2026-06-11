#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;

const ll mod = 1000000007;

ll power(ll x, ll y) {
    if(y == 1) {
        return x;
    }
    
    ll ans;
    if(y % 2 == 1) {
        ll r = power(x,(y-1)/2);
        ans = r * r % mod;
        ans = ans * x % mod;
    }
    else {
        ll r = power(x,y/2);
        ans = r * r % mod;
    }
    
    return ans;
}

ll comb(ll x, ll y) {
    ll c, p;
    c = p = 1;
    
    while(y >= 1) {
        c *= x;
        p *= y;
        c %= mod;
        p %= mod;
        x--;
        y--;
    }
    
    return c * power(p,mod-2) % mod;
}

int main() {
    ll n, k;
    cin >> n >> k;
    
    cout << comb(n-k+1,1) << endl;
    for(int i = 2; i <= k; i++) {
        ll b = comb(k-i+(i-1),i-1);
        ll r = comb((n-k)-(i-1)+i,i);
        
        //cout << b << " " << r << endl;
        cout << (b * r) % mod << endl;
    }
    
    
    return 0;
}


