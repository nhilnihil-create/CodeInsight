#include<bits/stdc++.h>
using namespace std;

long long dp[1001][4098],ara[1002][13],tra[1002][2],n,m,mx=99999999999;

int on(int x,int ps)
{
    return x | (1<<ps);
}


bool ck(int x,int ps)
{
    return (bool)(x & (1<<ps));
}


long long solve(long long idx,long long mask)
{

    if(idx==m)
    {
        long long z; z=pow(2,n); z--;


        if(mask==z)return 0;
        else{  return mx;  }
    }
    else if(dp[idx][mask]!=-1)return dp[idx][mask];
    else
    {
        long long p,q,s,fr,sc,x,y,sz,cst,j;

        int r;

        p=solve(idx+1,mask);

        sz=tra[idx][1]; cst=tra[idx][0];

        r=mask;

        for(j=0;j<sz;j++)
        {
            s=ara[idx][j];

            if(ck(r,s)==false)
            {
                r=on(r,s);
            }

        }

        q=cst+solve(idx+1,r);

        dp[idx][mask]=min(p,q);  return dp[idx][mask];



    }


}

int main()
{


    long long i,j,a,b,c,ans;
    scanf("%lld %lld",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%lld %lld",&a,&b); tra[i][0]=a; tra[i][1]=b;

        for(j=0;j<b;j++)
        {
            scanf("%lld",&c);  ara[i][j]=c-1;

        }

    }

    memset(dp,-1,sizeof dp);

    ans=solve(0,0);

    if(ans<mx)printf("%lld\n",ans);
    else
    {
        printf("-1\n");
    }



    return 0;
}



