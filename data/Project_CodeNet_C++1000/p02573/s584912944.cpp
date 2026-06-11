#include <bits/stdc++.h>
#include <queue>
#define ll long long int
#define inf 3e18+1
#define all(v) (v).begin(),(v).end() 
#define N 200005
#define F first
#define S second
using namespace std;
ll mod=1e9+7;
ll parent[200005],sz[200005];
ll find(ll x){
    if(x==parent[x]) return x;
    return parent[x]=find(parent[x]);
}
void join(ll x,ll y) {
    ll a=find(x);
    ll b=find(y);
    if(a!=b) {
        if(sz[a]<=sz[b]) {
            swap(a,b);
        }
        parent[b]=parent[a];
        sz[a]+=sz[b];
    }
}
int main()
{
    // added the two lines below 
    ios_base::sync_with_stdio (false); 
    cin.tie(NULL);
    cout.tie(0);    
    ll test=1;//cin>>test;
    while(test--){
        ll n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            parent[i]=i;
            sz[i]=1;
        }
        while(m--){
            ll u,v;
            cin>>u>>v;
            join(u,v);
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,sz[find(i)]);
        }
        cout<<ans<<endl;
    }
    return 0;
}


