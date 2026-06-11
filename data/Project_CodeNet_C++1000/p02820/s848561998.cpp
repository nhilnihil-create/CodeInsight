#include<bits/stdc++.h>
using namespace std;

long long dp[100006][3],n,k,r,s,p;
string str;

long long solve(long long idx,long long sta)
{


    if(idx>n)return 0;
    else if(dp[idx][sta]!=-1)return dp[idx][sta];
    else
    {

        if(idx<=k)
        {

            long long rr,ss,pp,fr,sc,tr,rs;

            if(str[idx-1]=='r'){  rr=0; ss=0; pp=p;   }
            else if(str[idx-1]=='s'){  rr=r; ss=0; pp=0;     }
            else{  rr=0; ss=s; pp=0; }

            fr=rr+solve(idx+k,0);   sc=ss+solve(idx+k,1);  tr=pp+solve(idx+k,2);
            rs=max(fr,sc);  rs=max(rs,tr);  dp[idx][sta]=rs;  return dp[idx][sta];


        }
        else
        {
             long long rr,ss,pp,fr,sc,tr,rs;

             if(sta==0)
             {
                 if(str[idx-1]=='r'){   ss=0; pp=p;   }
                 else if(str[idx-1]=='s'){   ss=0; pp=0;     }
                 else{   ss=s; pp=0; }

                sc=ss+solve(idx+k,1);  tr=pp+solve(idx+k,2);
                rs=max(sc,tr);   dp[idx][sta]=rs;  return dp[idx][sta];


             }
             else if(sta==1)
             {
                 if(str[idx-1]=='r'){  rr=0; pp=p;   }
                 else if(str[idx-1]=='s'){  rr=r; pp=0;     }
                 else{  rr=0; pp=0; }

                fr=rr+solve(idx+k,0);    tr=pp+solve(idx+k,2);
                rs=max(fr,tr);   dp[idx][sta]=rs;  return dp[idx][sta];



             }
             else
             {
                 if(str[idx-1]=='r'){  rr=0; ss=0;   }
                 else if(str[idx-1]=='s'){  rr=r; ss=0;  }
                 else{  rr=0; ss=s;  }

                 fr=rr+solve(idx+k,0);   sc=ss+solve(idx+k,1);
                 rs=max(fr,sc);  dp[idx][sta]=rs;  return dp[idx][sta];

             }


        }



    }



}

int main()
{


    long long res=0,ans,i,j,a,b;
    scanf("%lld %lld",&n,&k);
    scanf("%lld %lld %lld",&r,&s,&p);

    cin>>str;


    memset(dp,-1,sizeof dp);

    for(i=1;i<=k;i++)
    {
        ans=solve(i,0);  res=res+ans;
    }


    printf("%lld\n",res);

    return 0;
}



