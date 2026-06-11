#include<bits/stdc++.h>
using namespace std;

#define ll long long int
const ll mod=1e9+7;
const ll sz=1e5+100;
vector<ll> ad[sz];
ll root;

ll tk[sz],k;

ll DFS(ll p,ll par,ll tot)
{
    tk[p]=tot%mod;
    int siz=ad[p].size();

    ll start=(p==root) ? k-1 : k-2;
    for(ll i=0;i<siz;i++)
    {
        ll x=ad[p][i];
        if( x != par){
            ll le=DFS(x,p,start);
            tk[p]=(tk[p] * le)%mod;
            start=max(0ll,start-1);
        }
    }

    return tk[p];
}

int main()
{
    ll x,y,n,m,p,q;
    cin>>n>>k;
    for(ll i=1;i<n;i++){
        cin>>p>>q;
        ad[p].push_back(q);
        ad[q].push_back(p);
    }

    root=1;
    ll ans=DFS(1,-1,k);
    cout<<ans<<'\n';
}

