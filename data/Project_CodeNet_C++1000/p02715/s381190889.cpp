#include<bits/stdc++.h>
using namespace std;

long long mod=1000000007;

long long bigmod(long long n,long long p)
{
     if(p==0)return 1;
     if(p%2==0)
     {
         long long ret=bigmod(n,p/2);
         return ((ret%mod)*(ret%mod))%mod;
     }
     else
        return ((n%mod)*(bigmod(n,p-1)%mod))%mod;
}

long long ara[100005];

int main()
{

    long long n,k,i,j,lp,ans=0,fr,sc,tr,p,q,r,z;

    scanf("%lld %lld",&n,&k);

    for(i=k;i>=1;i--)
    {

        p=k/i; fr=bigmod(p,n);

        sc=ara[i];

        if(fr>=sc)tr=fr-sc;
        else{ tr=(mod-sc)+fr;  }

        z=(tr*i)%mod;
        ans=(ans+z)%mod;

        for(j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                ara[j]=(ara[j]+tr)%mod;

                r=i/j;

                if(r!=i && r!=j)
                {
                    ara[r]=(ara[r]+tr)%mod;
                }

            }

        }

    }

    printf("%lld\n",ans);


    return 0;
}
