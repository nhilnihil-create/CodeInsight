#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ar[3001][8001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,t;
    cin>>n>>t;
    vector<pair<ll,ll>>v;
    for(ll i=0;i<=3000;i++)
    {
        for(ll j=0;j<=8000;j++)
        {
            ar[i][j]=0;
        }
    }
    ll a,b;
    for(ll i=1;i<=n;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    for(ll i=1;i<=n;i++)
    {
        a=v[i-1].first;
        b=v[i-1].second;
        for(ll j=1;j<=8000;j++)
        {
            ar[i][j]=ar[i-1][j];
            if(j-a<t && j-a>=0)
            {
                ar[i][j]=max(ar[i][j],ar[i-1][j-a]+b);
            }
        }
    }
    ll ans=0;
    for(ll i=0;i<=8000;i++)
    {
        //cout<<ar[n][i]<<endl;
        ans=max(ans,ar[n][i]);
    }
    cout<<ans;
}