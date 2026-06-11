#include<bits/stdc++.h>
#define    ll   long long int
#define    sz   200010
#define    md   1000000007
using namespace std;

ll dp[2010][2010];


ll ncr(ll n,ll r)
{
    ll i,j,p;

    for(i=0;i<=n;i++)
    {
       for(j=0;j<=min(i,r);j++)
       {
           if(i==0 || j==0)dp[i][j]=1;
           else
           {
               dp[i][j]=(dp[i-1][j-1]%md+dp[i-1][j]%md)%md;

           }
       }
    }

    return dp[n][r];
}

int main()
{


    ll n,k,i,j,p,d;

    scanf("%lld %lld",&n,&k);
    ncr(n,n);


    for(i=1;i<=k;i++)
    {
        p=(dp[n-k+1][i]%md*dp[k-1][i-1]%md)%md;

        printf("%lld\n",p);
    }



    return 0;
}
