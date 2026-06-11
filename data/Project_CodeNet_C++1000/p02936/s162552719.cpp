//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
bool sortbysec(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return (a.second<b.second);
}
const int m=2e5+7;
vector<ll>adj[m];
vector<bool>vis;
vector<ll>ans;
void dfs(ll v)
{
   vis[v]=true;
   for(ll i=0;i<adj[v].size();i++)
   {
       ll k=adj[v][i];
       if(!vis[k])
       {
           ans[k]+=ans[v];
           dfs(k);
       }
   }
}

int main()
{
  ios;
     int n,q;
    cin>>n>>q;
    ans.assign(n,0);
    vis.assign(n,false);
    for(int i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<q;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        ans[a]+=b;
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i])
            continue;
        dfs(i);
    }
    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;






}
//Alhamdulillah











