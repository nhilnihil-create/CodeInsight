#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

vector<vector<int>>g;

void addedge(ll x,ll y)
{
    g[x].push_back(y);
    g[y].push_back(x);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,e;
    cin>>n>>e;
    vector<int>h;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        h.push_back(x);
    }
    g.assign(n, vector<int>());
    for(int i=0;i<e;i++)
    {
        ll x,y;
        cin>>x>>y;
        addedge(--x,--y);
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        int flag=1;
        for(auto x:g[i])
            if(h[x]>=h[i])
                flag=0;
        ans+=flag;
    }
    cout<<ans<<endl;
    return 0;
}