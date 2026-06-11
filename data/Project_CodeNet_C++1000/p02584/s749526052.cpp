#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

const lld N = 200043;
const lld MOD = 1000000007;

lld add(lld x, lld y)
{
    x =((x%MOD)+(y%MOD))%MOD;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

lld mul(lld x, lld y)
{
    return ((x%MOD)*(y%MOD))% MOD;
}

lld binpow(lld x, lld y)
{
    lld z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

lld inv(lld x)
{
    return binpow(x, MOD - 2);
}

lld divide(lld x, lld y)
{
    return mul(x, inv(y));
}

// Combinations

/*
lld fact[N];

void precalc()
{
    fact[0] = 1;
    for(lld i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
}

lld C(lld n, lld k)
{
    return divide(fact[n], mul(fact[k], fact[n - k]));
}
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t,i,j;
    //cin>>t;
    t=1;
    while(t--)
    {
        lld x,k,d;
        cin>>x>>k>>d;
        x=abs(x);
        lld a=x/d;
        if(a<k)
        {
            x=x-a*d;
            k-=a;
            if(k%2==0)
                cout<<x<<endl;
            else
                cout<<min(abs(x+d),abs(x-d));
        }
        else
        {
            x=x-k*d;
            cout<<x<<endl;
        }
    }
}



