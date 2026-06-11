#include<bits/stdc++.h>
using namespace std;

#define mx 15
#define ll long long

vector<pair<int,int>>g[mx];

int n,m,k,ii;

void solve()
{
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       int x;
       scanf("%d",&x);
       for(int j=0;j<x;j++)
       {
           int u,v;
           scanf("%d%d",&u,&v);
           g[i].push_back({--u,v});
       }
   }
   int re=0;
   for(int i=0;i<(1<<n);i++)
   {
       bool f=true;
       for(int j=0;j<n;j++)
       {
           if(i & (1<<j))
           {
               for(auto it:g[j])
               {
                  // cout<<(i & (1<<it.first))<<endl;
                   if(it.second ^bool(i & (1<<it.first)))
                   {
                       f=false;
                       break;
                   }
               }
           }
           if(!f)break;
       }
       if(f)
       {
           re=max(re,__builtin_popcount(i));
       }
   }

   printf("%d\n",re);
}

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t=1;
   //scanf("%d",&t);
   while(t--)solve();
   return 0;
}
