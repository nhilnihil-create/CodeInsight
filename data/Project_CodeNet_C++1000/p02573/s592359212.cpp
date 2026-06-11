#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
using namespace std;
const int mod=1e9+7;

ll solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > grp(n);
    vector<int> a(n);
    for(int i=0;i<n;i++) a[i]=i,grp[i].push_back(i);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;u--,v--;
        if(a[u]==a[v]) continue;
        vector<int> &x=grp[a[u]],&y=grp[a[v]];
        if(x.size() > y.size()){
            for(int i:y) x.push_back(i),a[i]=a[u];
            y.clear();
        }
        else{
            for(int i:x) y.push_back(i),a[i]=a[v];
            x.clear();
        }
    }
    ll ans=0;
    for(auto v:grp) ans=max(ans,(ll)v.size());
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
