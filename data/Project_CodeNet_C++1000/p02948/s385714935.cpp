#include<bits/stdc++.h>
using namespace std;

vector<long long>adj[100005];

int main()
{


        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x=0,y=0,cnt=0,res=0,ttl=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        multiset<long long>mst,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld %lld",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%lld %lld",&a,&b);
            adj[a].push_back(b);

        }

        for(i=1;i<=m;i++)
        {

           sz=adj[i].size();
           for(j=0;j<sz;j++)
           {
               fr=adj[i][j]; mst.insert(fr);
           }

           if(!mst.empty())
           {
               d=*mst.rbegin(); ans=ans+d; mst.erase(mst.lower_bound(d));
           }

        }


        printf("%lld\n",ans);






    return 0;
}



