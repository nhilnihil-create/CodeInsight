#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

const lld N = 200043;
const lld MOD = 1000000007;

lld add(lld x, lld y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

lld mul(lld x, lld y)
{
    return (x * 1ll * y) % MOD;
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
lld n,m;
string str[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t,i,j;
    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
            cin>>str[i];
        lld dp[n][m];
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            dp[i][j]=10000000;
    // (0,0)-->(n-1,m-1)
    //dp[i][j]--> yahan tak jane ka cost
        if(str[0][0]=='#')
        dp[0][0]=1;
        else
            dp[0][0]=0;
        for(i=1;i<n;i++)
            {if((str[0][i]==str[0][i-1]) || (str[0][i]=='.'))
            dp[0][i]=dp[0][i-1];
            else
            dp[0][i]=dp[0][i-1]+1;
            }
        for(i=1;i<n;i++)
            if((str[i][0]==str[i-1][0])||str[i][0]=='.')
            dp[i][0]=dp[i-1][0];
        else
            dp[i][0]=dp[i-1][0]+1;
        for(i=1;i<n;i++)
        {
            for(j=1;j<m;j++)
            {   lld ans=10000000;
                if((str[i-1][j]==str[i][j]) || str[i][j]=='.')
                    ans=min(ans,dp[i-1][j]);
                else
                    ans=min(ans,dp[i-1][j]+1);
                if((str[i][j-1]==str[i][j]) || str[i][j]=='.')
                    ans=min(ans,dp[i][j-1]);
                else
                    ans=min(ans,dp[i][j-1]+1);
                dp[i][j]=ans;
            }
        }

        cout<<dp[n-1][m-1]<<endl;

    }

}

