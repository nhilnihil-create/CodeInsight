#include<bits/stdc++.h>
using namespace std;

int dp[2][512][256],ara[12][12][12],z=0;


int on(int x,int ps)
{
    return x | (1<<ps);
}


bool ck(int x,int ps)
{
    return (bool)(x & (1<<ps));
}

int main()
{

    int n,m,q,a,b,c,d,i,j,k,mx=0,idx,mask1,mask2,l,fr,sc;
    vector<int>v;

    scanf("%d %d %d",&n,&m,&q);

    for(i=1;i<=q;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d); ara[a][b][c]=d;

        if(d>mx)mx=d;

    }


    if(n==2)printf("%d\n",mx);
    else
    {

        for(idx=n-1;idx>=1;idx--)
        {
            fr=idx%2; sc=(idx+1)%2;

            for(mask1=0;mask1<=511;mask1++)
            {
                for(mask2=0;mask2<=255;mask2++)
                {
                     if(idx==n-1)
                     {

                         int sz=1,t=0,e,f,g,h,r,mx=1,p=0; v.push_back(1);

                         for(i=0;i<=8;i++)
                         {
                             if(ck(mask1,i)==true){  v.push_back(i+2); if(i+2>mx)mx=i+2;  sz++; }
                         }

                         for(i=mx;i<=m;i++)
                         {
                             h=ara[1][idx+1][i-1]; t=0;

                             for(j=1;j<idx;j++)
                             {
                                 if(ck(mask2,j-1)==true)t++;

                                 if(t==sz){ h=-1; break;  }      f=v[t];    h=h+ara[j+1][idx+1][i-f];

                             }

                             if(t!=sz-1)h=-1;

                             p=max(p,h);

                         }

                         dp[fr][mask1][mask2]=p;


                     }
                     else
                     {
                         int sz=1,t=0,e,f,g,h,r,mx=1,p=0; v.push_back(1);

                         for(i=0;i<=8;i++)
                         {
                             if(ck(mask1,i)==true){  v.push_back(i+2); if(i+2>mx)mx=i+2;  sz++; }
                         }

                         for(i=mx;i<=m;i++)
                         {
                             h=ara[1][idx+1][i-1]; t=0;

                             for(j=1;j<idx;j++)
                             {
                                 if(ck(mask2,j-1)==true)t++;

                                 if(t==sz){  h=-1; break; }    f=v[t]; h=h+ara[j+1][idx+1][i-f];

                             }

                             if(t!=sz-1){ h=-1; }

                             if(h!=-1){
                             e=mask1; g=mask2; if(i>mx){ e=on(mask1,i-2);  g=on(mask2,idx-1);   }

                             p=max(p,h+dp[sc][e][g]);

                             }

                         }

                         dp[fr][mask1][mask2]=p;

                     }

                     v.clear();

                }

            }

        }


        printf("%d\n",dp[1][0][0]);


    }



    return 0;
}
