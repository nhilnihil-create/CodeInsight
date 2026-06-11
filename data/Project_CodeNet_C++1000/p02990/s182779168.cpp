#include<bits/stdc++.h>
using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<lli, lli> pi;

lli fac[2002], inv[2002], mod = 1000000007;

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
    if(r > n) return 0LL;
    lli ret;
    ret = (fac[n]*inv[r]) % mod;
    ret = (ret*inv[n-r]) % mod;
    return ret;
}

int main()
{
    fac[0] = 1;
    inv[0] = bigmod(1, mod-2, mod);
    for(lli i=1; i<=2001; i++){
        fac[i] = (i*fac[i-1]) % mod;
        inv[i] = bigmod(fac[i], mod-2, mod);
    }
    lli n, k;
    cin >> n >> k;
    lli x = n-k+1;
    for(lli i=1; i<=k; i++){
        if(i == 1LL){
            cout << ncr(x, i) << "\n";
        }
        else{
            cout << (ncr(k-1, i-1)*ncr(x, i))%mod << "\n";
        }
    }

    return 0;
}
