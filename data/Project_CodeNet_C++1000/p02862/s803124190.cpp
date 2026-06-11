#include<bits/stdc++.h>
using namespace std;

long long mod=1000000007;
long long ara[1000009];

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


int main()
{


        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,t,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x=0,y=0,cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld %lld",&x,&y);

        ara[0]=1;

        for(i=1;i<=1000004;i++)
        {
            ara[i]=(ara[i-1]*i)%mod;
        }

        for(i=0;i<=x;i++)
        {

            f=i*2; g=x-f; if(f>x)break;

            t=i+g;

            a=g*2; b=i; fr=f+g; sc=a+b;

            if(fr==x && sc==y)
            {
                d=(ara[i]*ara[t-i])%mod;
                e=bigmod(d,mod-2); q=(ara[t]*e)%mod; ans=ans+q;

            }


        }

        printf("%lld\n",ans);






    return 0;
}



