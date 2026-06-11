#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll vis[100010];
queue<ll>q;
vector<ll>v[100010];
void bfs(ll x)
{
    vis[x]=1;
    q.push(x);
    while(!q.empty())
    {
        ll p=q.front();
        q.pop();
        for(ll i=0;i<v[p].size();i++)
        {
            ll y=v[p][i];
            if(vis[y]==0)
            {
                vis[y]=1;
                q.push(y);
            }
        }

    }

}

int main()
{
    ll t=1,i,j,k=0,q,p,x,y,z,n,m,a,b,r,c,d;
    //cin>>t;
    while(t--)
    {
       cin>>n>>m;
       for(i=0;i<m;i++)
       {
           cin>>x>>y;
           v[x].push_back(y);
           v[y].push_back(x);
       }
       memset(vis,0,sizeof(vis));
       ll cnt=0;
       for(i=1;i<=n;i++)
       {
           if(vis[i]==0)
           {
               cnt++;
               bfs(i);
           }
       }
cout<<cnt-1<<endl;

    }
    return 0;
}

