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
        lld n,m,x;
        cin>>n>>m>>x;
        lld ar[n];
        lld br[n][m];
        for(i=0;i<n;i++)
        {
            cin>>ar[i];
            for(j=0;j<m;j++)
                cin>>br[i][j];
        }
        lld ans=LLONG_MAX;
        lld mask=(1<<n);
        for(i=0;i<mask;i++)
        {
            lld dp[m]={0};
            lld ctr=0;
            //cout<<i<<" i"<<endl;
            for(j=0;j<n;j++)
            {  // cout<<"1<<j"<<" "<<(1<<j)<<" "<<((1<<j)&i)<<endl;
                if(((1<<j)&i))
                {   //cout<<j<<" j"<<endl;
                    ctr+=ar[j];
                    for(lld k=0;k<m;k++)
                        dp[k]+=br[j][k];
                }
            }
            //cout<<ctr<<endl;
            bool ok=true;
            for(j=0;j<m;j++)
                if(dp[j]<x)
                ok=false;
            if(ok)
                ans=min(ans,ctr);
        }
        if(ans==LLONG_MAX)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
}



