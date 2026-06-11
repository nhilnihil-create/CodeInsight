#include<bits/stdc++.h>
using namespace std;

int main()
{

        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x,y=0,cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld",&n);

        if(n==2)printf("1\n");
        else
        {
            x=n-1;

            for(i=1;i*i<=x;i++)
            {
                if(x%i==0)
                {
                    fr=i; sc=x/i;

                    if(fr!=1){  mp[fr]=1; cnt++;  }
                    if(sc!=fr){mp[sc]=1; cnt++;}
                }

            }

            cnt++;

            for(i=2;i*i<=n;i++)
            {
                if(n%i==0)
                {
                    fr=i; sc=n/i;

                    if(mp[fr]==0){ v.push_back(fr); }
                    if(sc!=fr){if(mp[sc]==0){ v.push_back(sc);   } }
                }

            }

            sz=v.size();

            for(i=0;i<sz;i++)
            {
                fr=v[i];

                f=n;

                while(1)
                {
                    if(f%fr==0)
                    {
                        f=f/fr; if(f==1){ cnt++; break;  }
                    }
                    else
                    {
                        if(f%fr==1)cnt++;

                        break;
                    }

                }

            }

            printf("%lld\n",cnt);


        }










    return 0;
}



