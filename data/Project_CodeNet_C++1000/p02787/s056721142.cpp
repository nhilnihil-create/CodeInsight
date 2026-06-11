#include<bits/stdc++.h>
using namespace std;

long long dp[2][10003];

int main()
{


        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=99999999999;
        long long x=0,y=0,cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld %lld",&h,&n);

        for(i=1;i<=n;i++)
        {
            scanf("%lld %lld",&a,&b);  vct.push_back(make_pair(a,b));

        }

        long long idx,cap;

        for(idx=n-1;idx>=0;idx--)
        {
            for(cap=1;cap<=h;cap++)
            {
                a=vct[idx].first; b=vct[idx].second; fr=idx%2; sc=(idx+1)%2;

                if(idx==n-1)
                {
                    long long p=mn,q=mn,d,e,f;

                    if(cap-a<=0)d=b;
                    else{ d=b+dp[fr][cap-a];  }

                    e=q;

                    dp[fr][cap]=min(d,e);

                }
                else
                {

                    long long p=mn,q=mn,d,e,f;

                    if(cap-a<=0)d=b;
                    else{   d=b+dp[fr][cap-a];   }

                    e=dp[sc][cap];

                    dp[fr][cap]=min(d,e);

                }


                //cout<<idx<<" "<<cap<<"    "<<dp[fr][cap]<<endl;



            }
        }






       printf("%lld\n",dp[0][h]);







    return 0;
}


