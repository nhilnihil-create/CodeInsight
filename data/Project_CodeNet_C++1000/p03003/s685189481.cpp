#include<bits/stdc++.h>
using namespace std;

long long ara[2003][2003],tra[2003][2003],val[2003],tal[2003];
long long mod=1000000007;

int main()
{

    long long n,m,i,j,k,x,y,z,p,q,r,a,b=1;

    scanf("%lld %lld",&n,&m);

    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a); val[i]=a;
    }

    for(i=1;i<=m;i++)
    {
        scanf("%lld",&a);  tal[i]=a;
    }


    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {

            if(val[i]==tal[j])
            {

                if(i==1 || j==1)ara[i][j]=1;
                else
                {
                    p=i-1; q=j-1;
                    ara[i][j]=(tra[p][q]+1)%mod;
                }

            }


            b=(b+ara[i][j])%mod;

            x=(tra[i-1][j]+tra[i][j-1]+ara[i][j])%mod;
            y=tra[i-1][j-1];

            if(x>=y)z=x-y;
            else{  z=(mod-y)+x;  }

            tra[i][j]=z;

        }
    }

    printf("%lld\n",b);


    return 0;
}
