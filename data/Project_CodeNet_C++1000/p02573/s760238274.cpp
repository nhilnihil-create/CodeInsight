#include<bits/stdc++.h>
using namespace std;
#define int  long long int
#define fi first
#define se second
#define pb push_back
#define soo(v) sort(v.rbegin(),v.rend())
#define so(v) sort(v.begin(),v.end())
#define lb(v,x) lower_bound(v.begin(),v.end(),x)
#define ub(v,x) upper_bound(v.begin(),v.end(),x)
//#define endl '\n'
#define dbv(v) cout<<endl;cout<<#v<<"-->> ";for(auto it:v){cout<<it<<" ";}cout<<endl;
#define dbm(m)cout<<endl;cout<<#m<<"-->> ";for(auto it:m){cout<<it.fi<<" "<<it.se<<endl;}
#define dbs(s)cout<<endl;cout<<#s<<"-->> ";for(auto it:s){cout<<it<<" ";}cout<<endl;
#define mod 1000000007
#define db1(x) cout<<#x<<"="<<x<<endl;
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl;
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl;
#define mx 1e18
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v)  *min_element(v.begin(),v.end())
#define double long double
#define io std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
int kk=0;vector<vector<int>>v;vector<bool>vis;
void dfs(int root)
{
  vis[root]=1;kk++;
  for(int i=0;i<v[root].size();i++)
  {
    if(!vis[v[root][i]])
    {
      dfs(v[root][i]);
    }
  }
}
int32_t main()
{
    io
 int n,m;cin>>n>>m;
 v.resize(n+1);kk=0;
 vis.assign(n+1,0);
 int x,y;int ans=0;
 while(m--)
 {
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
 }
for(int i=1;i<=n;i++)
{
  if(!vis[i])
  {
    dfs(i);
    ans=max(ans,kk);
    kk=0;
  }
}
cout<<ans<<endl;


    
}