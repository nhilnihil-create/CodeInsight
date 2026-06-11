#include<bits/stdc++.h>
using namespace std;

long long spf[1000009];

int main()
{


        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mn=LLONG_MAX;
        long long cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;


        /*long long x,y,z,mx=1000002,lp,lim,tp; lim=sqrt(mx)+9; spf[1]=1; spf[2]=2;

        for(lp=3; lp<=mx; lp+=2)
        {
        if(spf[lp]==0)
        {
            spf[lp]=lp;

            if(lp<=lim)
            {
                y=lp << 1;

                for(tp=lp+y; tp<=mx; tp+=y)
                {
                    if(spf[tp]==0){  spf[tp]=lp;  }
                }

            }

        }

       }*/


        scanf("%lld %lld",&a,&b);
        //fr=min(a,b); sc=max(a,b);

        n=__gcd(a,b);

        if(n%2==0)
        {
            ans++;
            while(n%2==0)
            {
                n=n/2;
            }
        }

        for(i=3;i*i<=n;i++)
        {

            if(n%i==0)
            {
                ans++;

                while(n%i==0){  n=n/i;  }

            }


        }

        if(n>1)ans++;

        ans++;  printf("%lld\n",ans);


        /*for(i=1;i*i<=fr;i++)
        {
            if(fr%i==0)
            {
                cnt++;

                j=fr/i;

                if(sc%i==0){ mp[i]++;  if(i<=mx){   if(spf[i]==i && mp[i]==1)ans++;  }  }
                if(sc%j==0){ mp[j]++;  if(j<=mx){   if(spf[j]==j && mp[j]==1)ans++;  }  }

            }

        }

        if(fr==sc && fr>mx && cnt==1)ans++;

        printf("%lld\n",ans);*/










    return 0;
}



