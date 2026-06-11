#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

ll mod_pow(ll x, ll n, ll mod){ // x ^ n % mod
    ll res = 1;
    while(n > 0){
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    ll ans = 0;
    ll a[n+1] = {};
    rep(i,n){
        a[i] = s[i] - '0';
    }

    if(p == 2 || p == 5){
        rep(i,n){
            if(a[i] % p == 0){
                ans += i + 1;
            }
        }
        cout << ans << endl;
        return 0;
    }


    ll f[n+1] = {};
    ll g[n+1] = {};

    rep(i,n){
        g[i] = a[i] * mod_pow(10, n-1-i, p);
    }
    drep(i,n){
        f[i] = (f[i+1] + g[i]) % p;
    }

    ll b[p+1] = {};
    rep(i,n+1){
        b[f[i]]++;
    }

    rep(i,p+1){
        ans += b[i] * (b[i]-1) / 2;
    }

    cout << ans << endl;
    return 0;
}


