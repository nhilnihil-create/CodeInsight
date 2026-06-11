#include<bits/stdc++.h>
using namespace std;

int main()
{

        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x=0,y=0,cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld",&n);

        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a);  v.push_back(a);
        }

        sort(v.begin(),v.end());

        vector<long long>::iterator it;

        for(i=0;i<=n-3;i++)
        {
            for(j=i+1;j<=n-2;j++)
            {

                fr=v[i]+v[j];

                it=lower_bound(v.begin(),v.end(),fr); sc=it-v.begin();  sc--; ans=ans+max(0LL,sc-j);

            }

        }




        printf("%lld\n",ans);






    return 0;
}



