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
vector<pair<lld,lld>>v[5005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t,i,j;
    //cin>>t;
    t=1;
    while(t--)
    {
        lld n,k;
        cin>>n>>k;
        lld ar[n+1];
        lld br[n+1];
        for(i=1;i<=n;i++)
            cin>>ar[i];
        for(i=1;i<=n;i++)
            cin>>br[i];
        lld ans=LLONG_MIN;
        lld b;
        for(i=1;i<=n;i++)
        {
            lld visited[n+1]={0};
            lld a=i;
            b=k;
            lld ctr=0;
            lld c=0;
            lld gtr=0;
            lld d=0;
            while(!visited[a] && b)
            {
                visited[a]=1;
                a=ar[a];
                ctr+=br[a];
                b--;
                c++;
                ans=max(ans,ctr);
            }
            memset(visited,0,sizeof(visited));
            lld x=max(0ll,(b-c)/c);
            ctr+=x*(ctr);
            b=b-x*c;
            a=i;
            ans=max(ans,ctr);
            while(b--)
            {a=ar[a];
                ctr+=br[a];
                ans=max(ans,ctr);
            }

        }
        cout<<ans<<endl;

    }
}



