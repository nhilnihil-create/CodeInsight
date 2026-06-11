#include<bits/stdc++.h>
using namespace std;

int main()
{


        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x=0,y=0,cnt=0,res=0,ttl=0,ans,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<string,long long>mp; string str,ttr,ntr;
        map<char,long long>nq;

        scanf("%lld",&n);
        cin>>str;

        long long lo=0,hi=n/2,mid;

        for(i=0;i<n;i++)
        {
            nq[str[i]]++; if(nq[str[i]]==2){  lo=1;  break;  }
        }

        if(lo==0)printf("%lld\n",lo);
        else
        {

            while(lo<hi)
            {

                mid=(lo+hi) >> 1; flg=0;


                for(i=0;i<=n-mid;i++)
                {
                    ttr=str.substr(i,mid);

                    if(mp[ttr]==0){  mp[ttr]=i+1; }


                }

                for(i=n-mid;i>=0;i--)
                {
                    ttr=str.substr(i,mid);


                    if(mp[ttr]!=0)
                    {
                        p=mp[ttr]+mid-1; q=i+1;
                        if(q>p){  flg=1; break; }
                    }

                }

                if(flg==1)
                {
                    ans=mid; lo=mid+1;

                    if(lo==hi)
                    {

                        ///

                             mid=(lo+hi) >> 1; flg=0;

                             for(i=0;i<=n-mid;i++)
                             {
                                    ttr=str.substr(i,mid);

                                    if(mp[ttr]==0){  mp[ttr]=i+1; }

                            }

                            for(i=n-mid;i>=0;i--)
                            {
                                 ttr=str.substr(i,mid);


                                 if(mp[ttr]!=0)
                                 {
                                      p=mp[ttr]+mid-1; q=i+1;
                                      if(q>p){  flg=1; break; }
                                 }

                            }

                            if(flg==1)
                            {
                                ans=mid;
                            }

                        ///

                    }


                }
                else
                {
                    hi=mid;
                }


            }


            printf("%lld\n",ans);


        }








    return 0;
}



