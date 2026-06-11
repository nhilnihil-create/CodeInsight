#include<bits/stdc++.h>
using namespace std;

bool ck(long long x,long long ps)
{
    return (bool)(x & (1LL<<ps));
}

int main()
{

        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mod=1000000007;
        long long x=0,y=0,cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld",&n);

        qr[0]=1;

        for(i=1;i<=61;i++)
        {
            qr[i]=(qr[i-1]*2)%mod;
        }

        for(i=0;i<n;i++)
        {

            scanf("%lld",&a); v.push_back(a);

            for(j=0;j<=61;j++)
            {
                if(ck(a,j)==true)
                {
                    mp[j]++;
                }
                else
                {
                    nq[j]++;
                }

            }


        }


        for(i=0;i<n-1;i++)
        {

            a=v[i];

            for(j=0;j<=61;j++)
            {

               if(ck(a,j)==true)
               {
                   fr=qr[j];  g=nq[j]; sc=(fr*g)%mod; ans=(ans+sc)%mod;  mp[j]--;

               }
               else
               {
                   fr=qr[j];  g=mp[j];  sc=(fr*g)%mod; ans=(ans+sc)%mod;  nq[j]--;

               }



            }


        }



        printf("%lld\n",ans);





    return 0;
}



