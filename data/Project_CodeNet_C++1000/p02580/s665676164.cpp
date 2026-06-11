#include <bits/stdc++.h>
#define ll  long long int
#define fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
using namespace std;

int main()
    {fast;
    ll t =1;
    //cin>>t;

while(t--){
    
    ll h,w,m;
    cin>>h>>w>>m;
    vector<ll> a[h+1], b[w+1];
    map<ll,bool> che[h+1];
    ll ma=-1, mi=-1, mh=-1, mw=-1;

ll s=0;
    while(m--){
        ll u,v;
        cin>>u>>v;
        a[u].push_back(v);
        b[v].push_back(u);
       ll n = a[u].size();
        if(ma < n){
            mh = u;
            ma = a[u].size();      
        }
n = b[v].size();
        if(mi < n){
            mw = v;
            mi = b[v].size();
        }
    che[u][v] = true;
    }


    ll ans = mi + ma -1;

    for(ll j=1; j<=w;j++)
        if(b[j].size()==mi)
        s++;

    for(ll i=1; i<=h;i++){
        ll po=0;
        for(auto j: a[i]){
            if(b[j].size()==mi)
            po++;
        }
        if(po!=s && a[i].size() == ma)
            {ans++;
            break;}
    }

    cout<<ans<<endl;
    
}
        return 0;
}