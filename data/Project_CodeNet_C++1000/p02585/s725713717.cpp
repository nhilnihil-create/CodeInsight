#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;

vector<ll>a(5005);
vector<ll>b(5005);
vector<ll>track;
bool vis[5005];

void dfs(int u, long long total_cycle)
{
    if(vis[u])
        return ;
    vis[u]=true;
    total_cycle+=b[u];
    track.push_back(total_cycle);
    dfs(a[u],total_cycle);
}
void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        a[i]--;
    }
    for(int i=0; i<n; i++)
        cin>>b[i];
    ll ans=-2e18;
    for(int i=0; i<n; i++)
    {
        memset(vis,false,sizeof(vis));
        dfs(i,0);

        ll m = (ll) track.size();
        if(track.back()>0 && k>=m)
        {
            ll cycles= k/m;
            ll left= k%m;
            ll maxi=-2e18;
            for(int x=0; x<(int)track.size(); x++)
                maxi=max(maxi,track[x]);
            ans=max(ans,(cycles-1)*(track.back())+maxi);
            maxi=-2e18;
            for(int x=0; x<left; x++)
                maxi=max(maxi,track[x]);
            ans=max(ans,(cycles*track.back()) + maxi);
        }
        else
        {
            for(int j=0; j<(min((int)track.size(),k)); j++)
            {
                ans=max(ans,track[j]);
            }
        }
        track.clear();
    }
    cout<<ans;
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}
