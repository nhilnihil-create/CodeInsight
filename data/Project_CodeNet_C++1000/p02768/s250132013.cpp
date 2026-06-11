#include<bits/stdc++.h>
using namespace std;

long long mod=1000000007,ara[200007];

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
        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x=0,y=0,cnt=0,res=0,ttl=0,ans,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld %lld %lld",&n,&a,&b);

        fr=bigmod(2LL,n); fr--;

        ara[0]=1;

        for(i=1;i<=b;i++)
        {
            ara[i]=(ara[i-1]*i)%mod;
        }

        f=a; g=n-a; d=min(f,g); e=max(f,g);

        p=1;

        for(i=n;i>e;i--)
        {
            p=(p*i)%mod;
        }

        q=bigmod(ara[d],mod-2); r=(p*q)%mod; sc=r;

        f=b; g=n-b; d=min(f,g); e=max(f,g);

        p=1;

        for(i=n;i>e;i--)
        {
            p=(p*i)%mod;
        }

        q=bigmod(ara[d],mod-2); r=(p*q)%mod; sc=(sc+r)%mod;


        if(fr>=sc)printf("%lld\n",fr-sc);
        else{  printf("%lld\n",mod-sc+fr);   }





    return 0;
}



