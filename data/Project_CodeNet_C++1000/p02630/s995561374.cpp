#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


void solve(){
    ll n;
    cin>>n;
    unordered_map<ll,ll> umap;
    ll sum=0;
    for(ll i=0; i<n; ++i){
        ll in;
        cin>>in;
        umap[in]++;
        sum += in;
    }
    // cout<<sum<<endl;
    
    // cout<<sum<<endl;
    ll q;
    cin>>q;
    while(q--){
        ll x,y;
        cin>>x>>y;
        sum += y*umap[x] - umap[x]*x;
        umap[y] += umap[x];
        umap[x] = 0;
        cout << sum << endl;

    }


}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int q;
    q=1;
    // cin>>q;
    while(q--) solve();


    return 0;
}