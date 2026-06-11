#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(long long i = 0; i < (n); i++)
using ll = long long;
using namespace std;

ll mod_mul(ll a, ll b, ll mod)
{
    return a % mod * (b % mod) % mod;
}

ll mod_pow(ll a, ll b, ll mod)
{
    if(b == 0) return 1;
    else if(b % 2 == 0){
        return mod_pow(mod_mul(a, a, mod), b/2, mod);
    } else{
        return mod_mul(a, mod_pow(a, b-1, mod), mod);
    }
}

ll mod_div(ll a, ll b, ll mod)
{
    return a % mod * mod_pow(b, mod - 2, mod) % mod;
}

int main()
{
    const ll mod = 1e9+7;
    ll x, y;
    cin >> x >> y;
    ll z = max(x,y);
    vector<ll>mod_facto(z+1);
    mod_facto[0] = 1;
    for(ll i = 1; i <= z; i++){
        mod_facto[i] = mod_mul(i, mod_facto[i - 1], mod);
    }
    rep(i,x+1){
        ll n = x, m = y, a = i, b = 0;
        n -= i;
        m -= 2 * i;
        if(n % 2 == 0) b = n / 2;
        if(b == m && n % 2 != 1){
            cout << mod_div(mod_facto[a + b], mod_mul(mod_facto[a], mod_facto[b], mod), mod) << endl;
            return 0;
        }
        if(m <= 0 || n <= 0) break; 
    }
    cout << 0 << endl;
    return 0;
}