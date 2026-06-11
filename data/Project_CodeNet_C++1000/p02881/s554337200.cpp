#include<bits/stdc++.h>
using namespace std;

int main()
{


        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x=0,y=0,cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld",&n);

        for(i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                p=i;  q=n/i;

                r=(p-1)+(q-1);  if(r<mn)mn=r;


            }

        }



        printf("%lld\n",mn);












    return 0;
}



