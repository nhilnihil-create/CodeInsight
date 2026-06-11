#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int mod=1e9+7;


ll solve(){
    int n,m;
    cin>>n>>m;
    vector<int> h(n);
    vector<vector<int> > adj(n);
    for(int &i:h) cin>>i;
    while(m--){
        int u,v;
        cin>>u>>v;u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        int x=1;
        for(int j:adj[i]) if(h[i]<=h[j]) x=0;
        ans+=x;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while(t--) cout<<solve()<<'\n';
    //while(t--) solve(),cout<<'\n';
    return 0;
}
