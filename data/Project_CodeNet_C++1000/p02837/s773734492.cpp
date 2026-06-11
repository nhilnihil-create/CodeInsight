#include<bits/stdc++.h>
using namespace std;

int dp[17][70001],ax[17][20],ay[17][20],ara[17],n;
map<int,int>mp;

int on(int x,int ps)
{

    return x | (1<<ps);

}


bool ck(int x,int ps)
{
    return (bool)(x & (1<<ps));
}


int solve(int idx,int mask)
{

    if(idx==n)
    {

       int cnt=0,x,y,i,j;

       for(i=0;i<=n;i++)
       {
           if(ck(mask,i)==true)
           {
               mp[i]=mask;  cnt++;

           }

       }



       for(i=0;i<=n;i++)
       {
           if(ck(mask,i)==true)
           {
               for(j=0;j<ara[i];j++)
               {
                   x=ax[i][j];  y=ay[i][j];

                   if((y==1 && mp[x]!=mask) || (y==0 && mp[x]==mask))
                   {
                       cnt=0; break;
                   }

               }

           }

           if(cnt==0)break;

       }


       return cnt;


    }
    else if(dp[idx][mask]!=-1)return dp[idx][mask];
    else
    {

        int s,p,q,r;  s=on(mask,idx);

        p=solve(idx+1,mask);
        q=solve(idx+1,s);

        r=max(p,q);  dp[idx][mask]=r;  return dp[idx][mask];


    }


}


int main()
{


    int a,b,c,i,j,ans;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {

        scanf("%d",&a); ara[i]=a;

        for(j=0;j<a;j++)
        {
            scanf("%d %d",&b,&c);  ax[i][j]=b-1;  ay[i][j]=c;
        }

    }

    memset(dp,-1,sizeof dp);
    ans=solve(0,0);

    printf("%d\n",ans);



    return 0;
}



