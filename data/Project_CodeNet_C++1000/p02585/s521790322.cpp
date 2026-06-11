/*
    ~A_Pessimist~:)
*/
 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
const int sz=50000;
ll ans=-5e18;
vector<ll>vec;
ll p[sz],c[sz];
bool vis[sz];
 
void dfs(ll node, ll presum)
{
    if(vis[node]) return;
 
    vis[node]=true;
 
    presum+=c[node];
 
    vec.push_back(presum);
 
    dfs(p[node], presum);
}
 
void solve()
{
    ll n,k,i,j,rem,temp,mx=0,cycle;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>p[i];
        p[i]--;
    }
    for(i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(i=0;i<n;i++)
    {
        memset(vis, false, sizeof vis);
        dfs(p[i],0);
        mx=-5e18;
 
        if(k>=vec.size() && vec.size() && vec.back()>0)
        {
            cycle=k/vec.size();
            rem=k%vec.size();
 
            temp=(cycle-1LL)*vec.back();
 
            for(j=0;j<vec.size();j++)
            {
                mx=max(mx, vec[j]);
            }
            ans=max(ans, temp+mx);
 
            mx=-5e18;
 
            for(j=0;j<rem;j++)
            {
                mx=max(mx, vec[j]);
            }
 
            temp=cycle*vec.back();
 
            ans=max(ans, temp+mx);
        }
        else
        {
            ll z=vec.size();
            for(j=0;j<min(z,k);j++)
            {
                ans=max(ans, vec[j]);
            }
        }
        vec.clear();
        temp=0;
    }
    cout<<ans<<endl;
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t=1;
   // cin>>t;
 
    while(t--)
    {
        solve();
    }
}