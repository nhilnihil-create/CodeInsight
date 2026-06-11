#include<bits/stdc++.h>
using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<lli, lli> pii;

lli mod = 1e9+7;

lli bigmod(lli a, lli b, lli m)
{
    lli gg = a%m;
    lli ret = 1;
    while(b){
        if(b%2){
            ret = (ret*gg) % m;
        }
        gg = (gg*gg) % m;
        b/=2;
    }
    return ret;
}

lli ncr(lli n, lli r)
{
    lli tr = r;
    lli up = 1;
    while(tr--){
        up = (up*n)%mod;
        n--;
    }
    n = 1;
    tr = r;
    lli down = 1;
    while(tr--){
        down = (down*n)%mod;
        n++;
    }

    lli ret = up;
    ret = (ret * bigmod(down, mod-2, mod)) % mod;
    return ret;
}

int main()
{
    lli n, a, b;
    cin >> n >> a >> b;
    lli ans = bigmod(2, n, mod) - 1;
    ans =  ans + mod + mod + mod + mod;
    ans -= ncr(n, a);
    ans -= ncr(n, b);
    ans %= mod;
    cout << ans << endl;

    return 0;
}
