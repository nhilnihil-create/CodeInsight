#include<bits/stdc++.h>
using namespace std;

long long mod=1000000007,sz,dp[100009][2];
string str;

long long solve(long long idx,long long sta)
{

    if(idx==sz)return 1;
    else if(dp[idx][sta]!=-1)return dp[idx][sta];
    else
    {

        long long p=0,q=0,r=0,fr,sc;

        if(sta==1 || str[idx]=='1')q=1;

        for(long long lp=0;lp<=q;lp++)
        {
            for(long long tp=0;tp<=q;tp++)
            {
                if(lp!=1 || tp!=1)
                {

                    fr=sta; if(lp==0 && tp==0 && str[idx]=='1')fr=1;

                    p=(p+solve(idx+1,fr))%mod;

                }

            }
        }



        dp[idx][sta]=p;  return dp[idx][sta];


    }


}

int main()
{


        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x=0,y=0,cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string ttr,ntr;

        cin>>str;

        sz=str.size();

        memset(dp,-1,sizeof dp);
        ans=solve(0,0);

        printf("%lld\n",ans);





    return 0;
}


