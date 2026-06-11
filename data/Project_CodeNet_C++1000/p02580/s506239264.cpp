#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const ll inf=(1e14);
ll solve(){
    int h,m,w;
    cin>>h>>w>>m;
    set<vector<int>> tgt;
    vector<int> r(h+1),c(w+1);
    while(m--){
        int u,v;
        cin>>u>>v;
        tgt.insert({u,v});
        r[u]++;c[v]++;
    }
    vector<pair<int,int> > rr,cc;
    int rmx=*max_element(r.begin(), r.end()),cmx=*max_element(c.begin(), c.end());
    for(int i=1;i<=h;i++) if(r[i]==rmx) rr.push_back({r[i],i});
    for(int i=1;i<=w;i++) if(c[i]==cmx) cc.push_back({c[i],i});
    for(auto x:rr){
        for(auto y:cc){
            if(!tgt.count({x.second,y.second})){
                return rmx+cmx;
            }
        }
    }
    return rmx+cmx-1;
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
