#include<bits/stdc++.h>
using namespace std;

long long ara[200003],vis[200003],ans[200003];
vector<long long>adj[200003];

void dfs(long long src,long long val)
{

    vis[src]=1; ans[src]=val+ara[src];
    long long sz=adj[src].size();

    for(long long lp=0;lp<sz;lp++)
    {
        long long u=adj[src][lp];

        if(vis[u]!=1)
        {
            dfs(u,ans[src]);
        }


    }



}

int main()
{

        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x=0,y=0,cnt=0,res=0,ttl=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld %lld",&n,&q);
        for(i=1;i<=n-1;i++)
        {
            scanf("%lld %lld",&a,&b);
            adj[a].push_back(b);  adj[b].push_back(a);

        }

        for(i=1;i<=q;i++)
        {
            scanf("%lld %lld",&a,&b); ara[a]=ara[a]+b;

        }

        dfs(1,0);

        for(i=1;i<=n;i++)
        {
            printf("%lld ",ans[i]);
        }




    return 0;
}



